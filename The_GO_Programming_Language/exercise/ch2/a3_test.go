/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
    "math/rand"
    "testing"
    "tgpl/popcount"
    "time"
)

var testInput [256]uint64

func init() {
    rand.Seed(time.Now().UnixNano())
    for i := range testInput {
        testInput[i] = rand.Uint64()
    }
}

func BenchmarkPopCount(b *testing.B) {
    for j := 0; j < b.N; j++ {
        r := 0
        for _, v := range testInput {
            r += popcount.PopCount(v)
        }
    }
}

func BenchmarkPopCountLoop(b *testing.B) {
    for j := 0; j < b.N; j++ {
        r := 0
        for _, v := range testInput {
            r += popcount.PopCountLoop(v)
        }
    }
}

func BenchmarkPopCountShift(b *testing.B) {
    for j := 0; j < b.N; j++ {
        r := 0
        for _, v := range testInput {
            r += popcount.PopCountShift(v)
        }
    }
}

func BenchmarkPopCountOr(b *testing.B) {
    for j := 0; j < b.N; j++ {
        r := 0
        for _, v := range testInput {
            r += popcount.PopCountOr(v)
        }
    }
}
