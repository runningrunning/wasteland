/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
	"flag"
	"strings"
	"tgpl/converter"
)

var f = flag.String("from", "", "Current format.")
var t = flag.String("to", "", "Target format.")

func main() {
	flag.Parse()

	for _, v := range flag.Args() {
		if *f != "" && *t != "" {
			converter.Convert(strings.ToLower(*f), strings.ToLower(*t), v)
		} else {
			converter.Enumerate(v)
		}
	}
}
