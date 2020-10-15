/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
	"fmt"
	"log"
	"net/http"
	"sync"
	"tgpl/lissajous"
	"tgpl/server"
)

var handlers map[string]server.Handler

func init() {
	handlers = make(map[string]server.Handler)
	handlers["/header"] = handler_header
	handlers["/path"] = handler_path
	handlers["/count"] = handler_counter
	handlers["/lissajous"] = handler_lissajous
}

func main() {
	server.Server("192.168.1.155", 8000, handlers)
}

var mu sync.Mutex
var count int

func handler_path(w http.ResponseWriter, r *http.Request) {
	mu.Lock()
	count++
	mu.Unlock()
	fmt.Fprintf(w, "URL.Path = %q\n", r.URL.Path)
}
func handler_counter(w http.ResponseWriter, r *http.Request) {
	mu.Lock()
	fmt.Fprintf(w, "Count %d\n", count)
	mu.Unlock()
}

func handler_header(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "%s %s %s\n", r.Method, r.URL, r.Proto)
	for k, v := range r.Header {
		fmt.Fprintf(w, "Header[%q] = %q\n", k, v)
	}
	fmt.Fprintf(w, "Host = %q\n", r.Host)
	fmt.Fprintf(w, "RemoteAddr = %q\n", r.RemoteAddr)
	if err := r.ParseForm(); err != nil {
		log.Print(err)
	}

	for k, v := range r.Form {
		fmt.Fprintf(w, "Form[%q] = %q\n", k, v)
	}
}

func handler_lissajous(w http.ResponseWriter, r *http.Request) {
	if err := server.ParseForm(r, lissajous.CurrentSet()); err != nil {
		fmt.Printf("ParseForm err: %v.\n", err)
	}
	lissajous.LissajousCustomized(w)
}
