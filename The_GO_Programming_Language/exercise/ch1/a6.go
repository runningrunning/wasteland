/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
	"os"
	"tgpl/lissajous"
)

func main() {
	lissajous.LissajousColorful(os.Stdout)
}

