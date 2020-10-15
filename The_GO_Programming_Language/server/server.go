/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package server

import (
	"fmt"
	"log"
	"net/http"
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

func Server(host string, port int, handlers map[string]Handler) {
	address := string(fmt.Sprintf("%s:%d", host, port))

	for h, f := range handlers {
		http.HandleFunc(h, f)
	}

	log.Fatal(http.ListenAndServe(address, nil))
}
