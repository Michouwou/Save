package main

import (
	"database/sql"
	"encoding/json"
	_ "github.com/go-sql-driver/mysql"
	"io/ioutil"
	"log"
	"os"
	"path"
	"strconv"
	"strings"
	"time"
)

type Configuration struct {
	Login          string `json:"login"`
	Password       string `json:"pass"`
	Host           string `json:"host"`
	Port           string `json:"port"`
	Base           string `json:"base"`
	Op             string `json:"op"`
	File           string `json:"file"`
	RefreshInPlace bool   `json:"in_place"`
	Bkp            string `json:"backup"`
}

func Write(str string, file *os.File, display bool) error {

	var date string

	if display {
		date = time.Now().Format("2006-01-02 15:04:05") + "\t"
	} else {
		date = ""
	}

	_, err := file.WriteString(date + str)
	return err
}

func ConnectToDB(conf Configuration) *sql.DB {

	db, err := sql.Open("mysql", conf.Login+":"+conf.Password+"@tcp("+conf.Host+":"+conf.Port+")/"+conf.Base)
	if err != nil {
		log.Println("Unable to connect to db :", err)
		return nil
	}

	err = db.Ping()
	if err != nil {
		log.Println("Unable to keep connection alive :", err)
		return nil
	}

	return db
}

func GetConfiguration(path string) *Configuration {
	var conf Configuration

	file, err := ioutil.ReadFile(path)
	if err != nil {
		log.Println("Unable to read file :", path, err)
		return nil
	}

	err = json.Unmarshal(file, &conf)
	if err != nil {
		log.Println("Unable to unmarshal file :", path, err)
		return nil
	}

	return &conf
}

var PreviousFile = ""

func RefreshFile(fileName string, conf *Configuration) *os.file {

	if conf.RefreshInPlace {

		fileToWriteTo, err := os.Create(fileName)
		if err != nil {
			log.Println("Unable to open file for writing")
			return nil
		}

		return fileToWriteTo
	} else {

		os.Rename(PreviousFile, strings.Trim(conf.Bkp, "/")+"/"+path.Base(PreviousFile))

		t := time.Now().UnixNano()
		strT := strconv.Itoa(t)
		PreviousFile = fileName + "_" + strT

		fileToWriteTo, err := os.Create(fileName + "_" + strT)
		if err != nil {
			log.Println("Unable to open file for writing")
			return nil
		}

		return fileToWriteTo
	}
}

func main() {

	conf := GetConfiguration(path)
	if conf == nil {
		return
	}

	log.Println("Connecting with :", conf.Login+":"+conf.Password+"@tcp("+conf.Host+":"+conf.Port+")/"+conf.Base)
	db := ConnectToDB(conf)
	if db == nil {
		return
	}

	nb := float64(0.0)
	date1 := ""
	date2 := ""
	var t1 time.Time
	var t2 time.Time

	for {

		file := RefreshFile(conf.File, conf)
		if err == nil {
			return
		}

		r, err := db.Query("select sum(cpm_micros)/1000000 from win_" + conf.Op + ";")
		if err != nil {
			log.Println("Unable to query db :", err)
			return
		}

		if r.Next() {
			err = r.Scan(&nb)
			if err != nil {
				log.Println("Error scanning value :", err)
				return
			}
		}
		r.Close()

		err = Write("\n", fileToWriteTo, false)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}

		err = Write("Dépensé depuis le début : "+strconv.FormatFloat(nb, 'f', 2, 64)+"\n", fileToWriteTo, true)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}

		r, err = db.Query("select min(created_at), max(created_at) from win_" + conf.Op + ";")
		if err != nil {
			log.Println("Unable to query db :", err)
			return
		}

		if r.Next() {
			err = r.Scan(&date1, &date2)
			if err != nil {
				log.Println("Error scanning value :", err)
				return
			}
		}
		r.Close()

		t1, err = time.Parse("2006-01-02 15:04:05", date1)
		if err != nil {
			log.Println("Date :", date1, "could not be parsed")
		}
		t2, err = time.Parse("2006-01-02 15:04:05", date2)
		if err != nil {
			log.Println("Date :", date2, "could not be parsed")
		}

		dur := t2.Sub(t1)
		hou, min := dur.Hours(), dur.Minutes()

		err = Write("Dépensé en moyenne par minute : "+strconv.FormatFloat(nb/min, 'f', 2, 64)+"\n", fileToWriteTo, true)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}
		err = Write("Dépensé en moyenne par heure : "+strconv.FormatFloat(nb/hou, 'f', 2, 64)+"\n", fileToWriteTo, true)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}

		today := float64(0.0)

		r, err = db.Query("select sum(cpm_micros)/1000000 from win_" + conf.Op + " group by substring(created_at, 1, 10) order by substring(created_at, 1, 10) desc limit 1;")
		if err != nil {
			log.Println("Uneable to query db :", err)
			return
		}

		if r.Next() {
			err = r.Scan(&today)
			if err != nil {
				log.Println("Error scanning value :", err)
			}
		}

		err = Write("Dépensé aujourd'hui : "+strconv.FormatFloat(today, 'f', 2, 64)+"\n", fileToWriteTo, true)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}

		r, err = db.Query("select sum(cpm_micros)/1000000, ssp_id.name from win_" + conf.Op + " join ssp_id on ssp_id.id = ssp_id group by ssp_id;")
		if err != nil {
			log.Println("Uneable to query db :", err)
			return
		}

		ssps := make(map[string]float64, 0)

		for r.Next() {
			var tmp1 string
			var tmp2 float64

			err = r.Scan(&tmp2, &tmp1)
			if err != nil {
				log.Println("Error scanning value :", err)
				return
			}

			ssps[tmp1] = tmp2
		}

		err = Write("Dépensé par ssp (en %) : ", fileToWriteTo, true)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}
		for k, v := range ssps {
			err = Write(k+":"+strconv.FormatFloat(v/nb*100.0, 'f', 2, 64)+" ", fileToWriteTo, false)
			if err != nil {
				log.Println("Error writing to file :", err)
				return
			}
		}
		err = Write("\n\n", fileToWriteTo, false)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}

		time.Sleep(time.Second * 60)
	}
}
