/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
    "strings"
    "testing"
)

func BenchmarkSlowCombined(b *testing.B) {
    for j := 0; j < b.N; j++ {
        var s, sep string
        for i := 0; i < len(a); i++ {
            s += sep + a[i]
            sep = " "
        }
    }
}

func BenchmarkCombined(b *testing.B) {
    for j := 0; j < b.N; j++ {
        strings.Join(a, " ")
    }
}
