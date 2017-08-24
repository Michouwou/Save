package errors

import (
	"log"
	"os"
)

func HandleError(err error, precise string, dump string) {
	if err != nil {
		log.Println(precise, dump, err)
		os.Exit(3)
	}
}
