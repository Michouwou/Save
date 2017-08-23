package tools

import (
	"log"
	"os"
)

func Usage() {
	log.Println("Wrong usage")
	os.Exit(2)
}

func GetArguments(args []string) map[string]string {

	var (
		finalArgs map[string]string
	)

	finalArgs = make(map[string]string)

	for cpt, arg := range args {
		switch arg {
		case "--configuration":
			finalArgs["config"] = args[cpt+1]
			cpt++
		default:
			if len(finalArgs) != 0 {
				return finalArgs
			}
			Usage()
		}
	}

	return finalArgs
}
