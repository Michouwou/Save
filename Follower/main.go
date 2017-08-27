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

var (
	beginning, end time.Time
	PreviousFile   = make(map[string]string, 0)
)

type DBInfo struct {
	Login    string `json:"login"`
	Password string `json:"pass"`
	Host     string `json:"host"`
	Port     string `json:"port"`
	Base     string `json:"base"`
}

type Configuration struct {
	Adex           DBInfo   `json:"adex"`
	CDB            DBInfo   `json:"CDB"`
	Op             string   `json:"op"`
	File           string   `json:"file"`
	RefreshInPlace bool     `json:"in_place"`
	Bkp            string   `json:"backup"`
	AvgMin         bool     `json:"average_minute"`
	AvgHou         bool     `json:"average_hour"`
	PathPress      string   `json:"config_pression"`
	Behaviour      []string `json:"behaviour"`
}

func Header() {
	log.Print("\x1b[36;1m")
	log.Println("///////////////////////////////////////////////////////////////")
	log.Println("//                                                           //")
	log.Println("//*       Follower V1.0.0                                    //")
	log.Println("//**      By Michel LEVIEUX                                  //")
	log.Println("//***                                                        //")
	log.Println("//****    The 26/08/2017, 17:07                              //")
	log.Println("//*****   --options to get the list of all options           //")
	log.Println("//******  --help arg_name to get help on a given arg         //")
	log.Println("//*******                                                    //")
	log.Println("///////////////////////////////////////////////////////////////\x1b[0m")
	log.Println()
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

func ConnectToDB(info DBInfo) *sql.DB {

	db, err := sql.Open("mysql", info.Login+":"+info.Password+"@tcp("+info.Host+":"+info.Port+")/"+info.Base)
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

func RefreshFile(fileName string, conf *Configuration, which string) *os.File {

	if conf.RefreshInPlace {

		fileToWriteTo, err := os.Create(fileName)
		if err != nil {
			log.Println("Unable to open file for writing")
			return nil
		}

		return fileToWriteTo
	} else {

		os.Rename(PreviousFile[which], strings.Trim(conf.Bkp, "/")+"/"+path.Base(PreviousFile[which]))

		t := time.Now().UnixNano()
		strT := strconv.FormatInt(t, 16)
		PreviousFile[which] = fileName + "_" + strT

		fileToWriteTo, err := os.Create(fileName + "_" + strT)
		if err != nil {
			log.Println("Unable to open file for writing")
			return nil
		}

		return fileToWriteTo
	}
}

func SingleQuery(query string, db *sql.DB, values ...interface{}) error {
	err := db.QueryRow(query).Scan(values...)
	if err != nil {
		log.Println("Error querying db or scanning values :", query, ";", err)
		return err
	}

	return nil
}

func GetTotalSpent(db *sql.DB, file *os.File, conf *Configuration) float64 {

	var (
		nb  float64
		err error
	)

	if err = SingleQuery("select sum(cpm_micros)/1000000 from win_"+conf.Op+";", db, &nb); err != nil {
		return 0
	}

	if err = Write("\n", file, false); err != nil {
		log.Println("Error writing to file :", err)
		return 0
	}

	if err = Write("Dépensé depuis le début : "+strconv.FormatFloat(nb, 'f', 2, 64)+"\n", file, true); err != nil {
		log.Println("Error writing to file :", err)
		return 0
	}

	return nb
}

func GetAveragePerMinuteAndPerHour(totalSpent float64, db *sql.DB, file *os.File, conf *Configuration) {

	var (
		date1, date2 string
		err          error
		t1, t2       time.Time
		dur          time.Duration
		hou, min     float64
	)

	if err = SingleQuery("select min(created_at), max(created_at) from win_"+conf.Op+";", db, &date1, &date2); err != nil {
		return
	}

	if t1, err = time.Parse("2006-01-02 15:04:05", date1); err != nil {
		log.Println("Date :", date1, "could not be parsed")
	}
	if t2, err = time.Parse("2006-01-02 15:04:05", date2); err != nil {
		log.Println("Date :", date2, "could not be parsed")
	}

	if !t1.Equal(beginning) && !beginning.Equal(time.Time{}) {
		Warning("Be careful, the starting time of", conf.Op, "has changed, this might be an error!")
	}
	beginning, end = t1, t2

	dur = t2.Sub(t1)
	hou, min = dur.Hours(), dur.Minutes()

	if err = Write("Dépensé en moyenne par minute : "+strconv.FormatFloat(totalSpent/min, 'f', 2, 64)+"\n", file, true); err != nil {
		log.Println("Error writing to file :", err)
		return
	}
	if err = Write("Dépensé en moyenne par heure : "+strconv.FormatFloat(totalSpent/hou, 'f', 2, 64)+"\n", file, true); err != nil {
		log.Println("Error writing to file :", err)
		return
	}

	return
}

func GetSpentToday(db *sql.DB, file *os.File, conf *Configuration) {

	var (
		today     float64
		dateToday string
		err       error
	)

	today = 0.0
	dateToday = time.Now().Format("2006-01-02")

	err = SingleQuery("select sum(cpm_micros)/1000000 from win_"+conf.Op+" where date(created_at) = \""+dateToday+"\";", db, &today)
	if err != nil {
		log.Println("Uneable to query db :", err)
		return
	}

	err = Write("Dépensé aujourd'hui : "+strconv.FormatFloat(today, 'f', 2, 64)+"\n", file, true)
	if err != nil {
		log.Println("Error writing to file :", err)
		return
	}
}

func GetSpentPerSspPercent(totalSpent float64, db *sql.DB, file *os.File, conf *Configuration) map[string]float64 {

	var (
		r    *sql.Rows
		err  error
		ssps map[string]float64
	)

	r, err = db.Query("select sum(cpm_micros)/1000000, ssp_id.name from win_" + conf.Op + " join ssp_id on ssp_id.id = ssp_id group by ssp_id;")
	if err != nil {
		log.Println("Uneable to query db :", err)
		return nil
	}

	ssps = make(map[string]float64, 0)

	for r.Next() {
		var (
			tmp1 string
			tmp2 float64
		)

		err = r.Scan(&tmp2, &tmp1)
		if err != nil {
			log.Println("Error scanning value :", err)
			return nil
		}

		ssps[tmp1] = tmp2
	}
	r.Close()

	err = Write("Dépensé par ssp (en %) : ", file, true)
	if err != nil {
		log.Println("Error writing to file :", err)
		return nil
	}

	for k, v := range ssps {
		err = Write(k+":"+strconv.FormatFloat(v/totalSpent*100.0, 'f', 2, 64)+" ", file, false)
		if err != nil {
			log.Println("Error writing to file :", err)
			return nil
		}
	}

	err = Write("\n", file, false)
	if err != nil {
		log.Println("Error writing to file :", err)
		return nil
	}

	return ssps
}

func GetSpentPerSspRaw(totalSpent float64, vPerSsp map[string]float64, db *sql.DB, file *os.File, conf *Configuration) {

	var (
		err error
	)

	err = Write("Dépensé par ssp (en €) : ", file, true)
	if err != nil {
		log.Println("Error writing to file :", err)
		return
	}

	for k, v := range vPerSsp {
		err = Write(k+":"+strconv.FormatFloat(v, 'f', 2, 64)+" ", file, false)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}
	}

	err = Write("\n", file, false)
	if err != nil {
		log.Println("Error writing to file :", err)
		return
	}
}

func GetSpentPerDevicePercent(totalSpent float64, file *os.File, db *sql.DB, conf *Configuration) map[string]float64 {

	var (
		err     error
		devices map[string]float64
		row     *sql.Rows
	)

	row, err = db.Query("select device_id.name, sum(cpm_micros)/1000000 from win_" + conf.Op + " join device_id on device_id.id = win_" + conf.Op + ".device_id group by device_id.name")
	if err != nil {
		log.Println("Error querying db :", err)
		return nil
	}

	err = Write("Dépensé par device (en %) : ", file, true)
	if err != nil {
		log.Println("Error writing to file :", err)
		return nil
	}

	devices = make(map[string]float64, 0)

	for row.Next() {
		var (
			tmp1 string
			tmp2 float64
		)

		err = row.Scan(&tmp1, &tmp2)
		if err != nil {
			log.Println("Error scanning value :", err)
			return nil
		}

		devices[tmp1] = tmp2
	}
	row.Close()

	for k, v := range devices {
		err = Write(k+":"+strconv.FormatFloat(v/totalSpent*100.0, 'f', 2, 64)+" ", file, false)
		if err != nil {
			log.Println("Error writing to file :", err)
			return nil
		}
	}

	err = Write("\n", file, false)
	if err != nil {
		log.Println("Error writing to file :", err)
		return nil
	}

	return devices
}

func GetSpentPerDeviceRaw(totalSpent float64, vPerDevice map[string]float64, db *sql.DB, file *os.File, conf *Configuration) {

	var (
		err error
	)

	err = Write("Dépensé par device (en €) : ", file, true)
	if err != nil {
		log.Println("Error writing to file :", err)
		return
	}

	for k, v := range vPerDevice {
		err = Write(k+":"+strconv.FormatFloat(v, 'f', 2, 64)+" ", file, false)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}
	}

	err = Write("\n", file, false)
	if err != nil {
		log.Println("Error writing to file :", err)
		return
	}
}

func MakeFileAveragePerMinuteOnHours(fileName string, db *sql.DB, conf *Configuration) {

	if conf.AvgMin {

		var (
			err  error
			file *os.File
			avg  sql.NullFloat64
		)

		file = RefreshFile(fileName, conf, "per_minute")
		if file == nil {
			return
		}

		for i := 0; i < 24; i++ {

			err = SingleQuery("select sum(cpm_micros) from win_"+conf.Op+" where created_at like \"% "+strings.Repeat("0", 2-len(strconv.Itoa(i)))+strconv.Itoa(i)+":%\"", db, &avg)
			if err != nil {
				return
			}

			if avg.Valid {
				err = Write(strings.Repeat("0", 2-len(strconv.Itoa(i)))+strconv.Itoa(i)+","+strconv.FormatFloat(avg.Float64/60, 'f', 4, 64)+"\n", file, false)
				if err != nil {
					return
				}
			}

		}
	}
}

func MakeFileAveragePerHourOnDays(fileName string, db *sql.DB, conf *Configuration) {

	if conf.AvgHou {

		var (
			err      error
			file     *os.File
			avg      sql.NullFloat64
			dayIndex time.Time
		)

		file = RefreshFile(fileName, conf, "per_hour")
		if file == nil {
			return
		}

		dayIndex = beginning

		for dayIndex.Before(end) {

			err = SingleQuery("select sum(cpm_micros)/1000000 from win_"+conf.Op+" where date(created_at) = \""+dayIndex.Format("2006-01-02")+"\"", db, &avg)
			if err != nil {
				return
			}

			if avg.Valid {
				err = Write(dayIndex.Format("2006-01-02")+","+strconv.FormatFloat(avg.Float64/24, 'f', 4, 64)+"\n", file, false)
				if err != nil {
					return
				}
			} else {
				Warning("Be careful, no money was spent on op :", conf.Op, "today, this might be an error!")
			}

			dayIndex = dayIndex.AddDate(0, 0, 1)
		}
	}
}

func CheckLastDateOfBehaviourUsed(conf *Configuration, db *sql.DB) {

	var (
		dates      map[string]time.Time
		err        error
		date       time.Time
		event_type string
		since      time.Duration
	)

	if len(conf.Behaviour) != 0 {

		dates = make(map[string]time.Time, 0)

		for _, behaviour := range conf.Behaviour {

			var tmp string
			err = SingleQuery("select event_contents_date from event_contents where source = \""+behaviour+"\" order by event_contents_date desc limit 1;", db, &tmp)
			if err != nil {
				return
			}

			dates[behaviour], err = time.Parse("2006-01-02 15:04:05", tmp)
			if err != nil {
				log.Println("Unable to parse string :", tmp, "as a date :", err)
				return
			}
		}

		threeMonths := time.Date(0, time.April, 0, 0, 0, 0, 0, time.UTC).Sub(time.Date(0, time.January, 0, 0, 0, 0, 0, time.UTC)).Hours()

		for event_type, date = range dates {

			since = time.Now().Sub(date)
			if since.Hours() > threeMonths {
				Warning("Be careful, the last occurence of event :", event_type, "is dated of more than three months!")
			}
		}
	}
}

func Warning(toPrint ...interface{}) {
	log.Println("\x1b[31;1m")
	toPrint = append(toPrint, "\x1b[0m")
	log.Println(toPrint...)
}

func main() {

	var (
		total         float64
		conf          *Configuration
		dbAdex        *sql.DB
		dbCDB         *sql.DB
		fileToWriteTo *os.File
		err           error
		ssps          map[string]float64
		devices       map[string]float64
	)

	Header()

	conf = GetConfiguration(os.Args[1])
	if conf == nil {
		return
	}

	log.Println("Connecting with :", conf.Adex.Login+":"+conf.Adex.Password+"@tcp("+conf.Adex.Host+":"+conf.Adex.Port+")/"+conf.Adex.Base)
	dbAdex = ConnectToDB(conf.Adex)
	if dbAdex == nil {
		return
	}

	log.Println("Connecting with :", conf.CDB.Login+":"+conf.CDB.Password+"@tcp("+conf.CDB.Host+":"+conf.CDB.Port+")/"+conf.CDB.Base)
	dbCDB = ConnectToDB(conf.CDB)
	if dbCDB == nil {
		return
	}

	go CheckLastDateOfBehaviourUsed(conf, dbCDB)

	for {

		if fileToWriteTo != nil {
			fileToWriteTo.Close()
		}

		fileToWriteTo = RefreshFile(conf.File+"_"+conf.Op, conf, "global")
		if fileToWriteTo == nil {
			return
		}

		total = GetTotalSpent(dbAdex, fileToWriteTo, conf)
		GetAveragePerMinuteAndPerHour(total, dbAdex, fileToWriteTo, conf)
		GetSpentToday(dbAdex, fileToWriteTo, conf)
		ssps = GetSpentPerSspPercent(total, dbAdex, fileToWriteTo, conf)
		GetSpentPerSspRaw(total, ssps, dbAdex, fileToWriteTo, conf)
		devices = GetSpentPerDevicePercent(total, fileToWriteTo, dbAdex, conf)
		GetSpentPerDeviceRaw(total, devices, dbAdex, fileToWriteTo, conf)
		err = Write("\n\n", fileToWriteTo, false)
		if err != nil {
			log.Println("Error writing to file :", err)
			return
		}

		MakeFileAveragePerMinuteOnHours("avg_per_minute_per_hour_"+conf.Op+".csv", dbAdex, conf)
		MakeFileAveragePerHourOnDays("avg_per_hour_per_day_"+conf.Op+".csv", dbAdex, conf)

		time.Sleep(time.Second * 60)
	}
}
