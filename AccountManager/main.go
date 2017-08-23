package main

import (
	configuration "./configuration"
	"./database"
	"./tools"
	"database/sql"
	"github.com/davecgh/go-spew/spew"
	_ "github.com/go-sql-driver/mysql"
	"os"
)

func main() {

	var (
		args   map[string]string
		config configuration.Configuration
		DB     *sql.DB
	)

	args = tools.GetArguments(os.Args[1:])
	if len(args) == 0 {
		tools.Usage()
		return
	}

	config = configuration.GetConfigurationFromPath(args["config"])
	DB = database.ConnectToDatabases(config)

	spew.Dump(config)
	spew.Dump(DB)
}
