/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
    "fmt"
    "tgpl/converter"
)

func main() {
    fmt.Printf("Brrrr! %v\n", converter.AbsoluteZeroC)
    fmt.Println(converter.CToF(converter.BoilingC))
    fmt.Println(converter.CToK(converter.AbsoluteZeroC))
    fmt.Println(converter.FToK(converter.CToF(converter.BoilingC)))
}
