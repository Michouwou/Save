package database

import (
	"../configuration"
	"../errors"
	"database/sql"
	_ "github.com/go-sql-driver/mysql"
)

func DNS(login string, pass string, host string, port string, db string) string {
	if login == "" {
		errors.HandleError(nil, "Login is missing", "")
	}

	if host == "" {
		errors.HandleError(nil, "Host name is missing", "")
	}

	if db == "" {
		errors.HandleError(nil, "DB name is missing", "")
	}

	if port == "" {
		errors.HandleError(nil, "Port is missing", "")
	}

	return login + ":" + pass + "@tcp(" + host + ":" + port + ")/" + db
}

func ConnectToDatabases(config configuration.Configuration) *sql.DB {

	var (
		conn *sql.DB
		err  error
	)

	// conn, err = sql.Open("mysql", DNS(config.Login, config.Password, config.Host, config.Port, config.Database))
	conn, err = sql.Open("mysql", "")
	errors.HandleError(err, "Unable to connect to database", config.Host+"/"+config.Database)

	err = conn.Ping()
	errors.HandleError(err, "Could not keep connection alive", "")

	return conn
}
