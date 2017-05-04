package main

import (
		"os"
		"fmt"
		"strings"
		"io/ioutil"
		"regexp"
		"database/sql"
		_ "github.com/go-sql-driver/mysql"
		)

func help() {
	fmt.Println("Invalid use")
	os.Exit(0)
}

func checkFileValidity(fileName string) bool {
	reg, _ := regexp.MatchString("[0-9]{8}_contacts.csv", fileName)
	if reg {
		return true
	}
	return false
}

func handleSQL(data [][]string, tx *sql.Tx, tableName string) {
	query := strings.Join([]string{"INSERT INTO ", tableName, " VALUES ((?), (?), (?), (?));"}, "")
	stmt, err := tx.Prepare(query)
	if err != nil {
		fmt.Println("Error during query prep, aborting")
		os.Exit(0)
	}
	for i := range data {
		_, err = stmt.Exec(data[i][0], data[i][1], data[i][2], data[i][3])
		if err != nil {
			fmt.Println("Values : ", data[i][0], data[i][1], data[i][2], data[i][3], " couldn't be inserted")
		}
	}
	err = tx.Commit()
	if err != nil {
		fmt.Println("Error commiting query, aborting")
		os.Exit(0)
	}
	stmt.Close()
}

func treatFolder(folderName string, strictness bool) [][]string{
	// Then we open that folder
	fil, err := os.Open(folderName)
	defer fil.Close()
	if err != nil {
		panic(err)
	}

	// We get all the names of the files the folder contains
	listFiles, err := fil.Readdir(10)
	listNames := make([]string, 0)
	for i := range listFiles {
		listNames = append(listNames, listFiles[i].Name())
	}

	// For each file name, we read the whole content and put it in
	// a list
	fileContents := make([]string, 0)
	for i := range listNames {
		if checkFileValidity(listNames[i]) {
			path := strings.Join([]string{folderName, listNames[i]}, "/")
			tmpFile, tmpErr := ioutil.ReadFile(path)
			if tmpErr != nil {
				fmt.Println("Error opening file : ", listNames[i])
				os.Exit(0)
			}
			fileContents = append(fileContents, string(tmpFile))
		} else {
			fmt.Println("File : ", listNames[i], " not treated")
		}
	}

	// For each content of the list, we split it according to
	// EOL and make a huge list
	parsedLines := make([]string, 0)
	for i := range fileContents {
		fileContents[i] = strings.Replace(fileContents[i], "\r", "", -1)
		fileContents[i] = strings.Replace(fileContents[i], " ", "", -1)
		tmpLines := strings.Split(fileContents[i], "\n")
		parsedLines = append(parsedLines, tmpLines...)
	}
	
	// Then we parse all the lines according to comas, and check the
	// number of fields of each line, paying attention not to take
	// empty lines as invalid
	cutData := make([][]string, 0)
	for i := range parsedLines {
		tmpData := strings.Split(parsedLines[i], ",")
		if len(tmpData) != 4 && !(len(tmpData) == 1 && len(tmpData[0]) == 0) {
			fmt.Println("Invalid format")
			os.Exit(0)
		}
		if len(tmpData) != 1 {
			cond1 := len(tmpData[0]) <= 50
			cond2 := len(tmpData[1]) <= 50
			cond3, _ := regexp.MatchString("^[a-zA-Z0-9._+\\-]+@[a-zA-Z0-9.\\-]+\\.[a-z]{2,4}$", tmpData[2])
			parseErr, _ := regexp.MatchString("[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}Z", tmpData[3])
			fmt.Println(parseErr, cond3)
			if cond1 && cond2 && cond3 && len(tmpData) <= 100 && parseErr == true {
				cutData = append(cutData, tmpData)
			}
		}
	}

	return cutData
}

func prepareDataBase(dbInfo string) (*sql.Tx, *sql.DB) {
	db, err := sql.Open("mysql", dbInfo)
	if err == nil {
		err = db.Ping()
		if err == nil {
			var tx, err = db.Begin()
			if err == nil {
				return tx, db
			}
		}
	}	
	if err != nil {
		fmt.Println("Error preparing database", err)
		os.Exit(0)
	}
	return nil, nil
}

func endDataBase(tx *sql.Tx, db *sql.DB) {
	tx.Rollback()
	db.Close()
}

func main() {
	// First we get the name of the folder where the csv files are
	argsUtils := os.Args[1:]
	strictness := false

	var cpt int
	dbInfo := argsUtils[0]
	tableName := argsUtils[1]
	if argsUtils[cpt] == "-s" {
		strictness = true
		cpt = 1
	}

	folderNames := argsUtils[cpt + 1:]

	tx, db := prepareDataBase(dbInfo)
	defer endDataBase(tx, db)

	for i := range folderNames {
		handleSQL(treatFolder(folderNames[i], strictness), tx, tableName)
	}
}




