// simple code
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	var rules [][]string
	circuit := make(map[string]int)

	value := func(s string) (int, bool) {
		if s[0] >= '0' && s[0] <= '9' {
			n, _ := strconv.Atoi(s)
			return n, true
		}
		v, ok := circuit[s]

		// // q2, override wire b with 3176
		// if s == "b" {
		// 	v = 3176
		// }

		return v, ok
	}

	for input.Scan() {
		ws := strings.Split(input.Text(), " ")
		rules = append(rules, ws)
	}

	for {
		found := false

		for i, ws := range rules {
			if ws == nil {
				continue
			}

			var v1, v2 int
			var ok bool

			if ws[0] == "NOT" {
				if v1, ok = value(ws[1]); ok {
					found = true
					// uint16 unsigned 16
					circuit[ws[3]] = int(^uint16(v1))
					rules[i] = nil
				}
			} else if ws[1] == "->" {
				if v1, ok = value(ws[0]); ok {
					found = true
					circuit[ws[2]] = v1
					rules[i] = nil
				}
			} else {
				if v1, ok = value(ws[0]); ok {
					if v2, ok = value(ws[2]); ok {
						found = true
						switch ws[1] {
						case "AND":
							circuit[ws[4]] = v1 & v2
						case "OR":
							circuit[ws[4]] = v1 | v2
						case "LSHIFT":
							circuit[ws[4]] = v1 << v2
						case "RSHIFT":
							circuit[ws[4]] = v1 >> v2
						}
						rules[i] = nil
					}
				}
			}
		}

		if !found {
			break
		}
	}

	fmt.Println(circuit, circuit["a"], circuit["b"])
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
