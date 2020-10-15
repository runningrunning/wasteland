/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
    "fmt"
    "os"
)

func main() {
    for i, s := range os.Args {
        fmt.Printf("%d\t%s\n", i, s)
    }
}
