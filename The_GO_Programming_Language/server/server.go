package server

import (
	"fmt"
	"log"
	"net/http"
	"tgpl/config"
	"tgpl/utils"
)

type Handler func(http.ResponseWriter, *http.Request)

func ParseForm(r *http.Request, x interface{}) error {
	if err := r.ParseForm(); err != nil {
		return err
	}

	var form = map[string]string{}
	for k, _ := range r.Form {
		form[k] = r.FormValue(k)
	}

	if err := utils.SetStruct(form, x); err != nil {
		return err
	}

	return nil
}

func Server(handlers map[string]Handler) {
	host := utils.OutboundIP()
	port := config.Port

	address := string(fmt.Sprintf("%v:%d", host, port))

	for h, f := range handlers {
		http.HandleFunc(h, f)
	}

	log.Fatal(http.ListenAndServe(address, nil))
}
