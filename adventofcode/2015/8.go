package main

import (
	"bufio"
	"fmt"
	"os"
)

func q1(f *os.File) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)

	sum := 0
	for input.Scan() {
		t := input.Text()
		if len(t) == 0 {
			continue
		}

		sum += 2
		t = t[1 : len(t)-1]
		for i := 0; i < len(t); i++ {
			if t[i] == '\\' {
				if t[i+1] == 'x' {
					i += 3
					sum += 3
				} else {
					i += 1
					sum += 1
				}
			}
		}
	}

	fmt.Println(sum)
}

func q2(f *os.File) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)

	sum := 0

	for input.Scan() {
		t := input.Text()
		if len(t) == 0 {
			continue
		}
		sum += 2

		for i := 0; i < len(t); i ++ {
			if t[i] == '"' || t[i] == '\\' {
				sum += 1
			}
		}
	}
	fmt.Println(sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	q2(f)
}
