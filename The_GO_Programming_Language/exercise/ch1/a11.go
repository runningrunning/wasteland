/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package main

import (
    "bufio"
    "fmt"
    "os"
    "tgpl/fetch"
    "time"
)

func main() {
    start := time.Now()
    ch := make(chan string)
    number := 0
    for _, file := range os.Args[1:] {
        f, err := os.Open(file)

        if err != nil {
            fmt.Fprintf(os.Stderr, "fetchall: %v.\n", err)
            continue
        }

        input := bufio.NewScanner(f)

        for input.Scan() {
            number++
            go fetch.FetchChan(input.Text(), ch)
        }
    }

    for ; number != 0; number-- {
        fmt.Println(<-ch)
    }

    fmt.Printf("%.2fs elapsed\n", time.Since(start).Seconds())
}
