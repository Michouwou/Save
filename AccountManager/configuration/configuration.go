package configuration

import (
	"../errors"
	"encoding/json"
	"io/ioutil"
)

type Configuration struct {
	Login     string `json:"login"`
	Password  string `json:"pass"`
	Host      string `json:"host"`
	Port      string `json:"port"`
	Database  string `json:"base"`
	Purchases string `json:"purchase"`
	Savings   string `json:"saving"`
	Types     string `json:"types"`
}

func GetConfigurationFromPath(path string) Configuration {

	var (
		file   []byte
		config Configuration
		err    error
	)

	file, err = ioutil.ReadFile(path)
	errors.HandleError(err, "Unable to read configuration", path)

	err = json.Unmarshal(file, &config)
	errors.HandleError(err, "Unable to unmarshal configuration", path)

	return config
}
