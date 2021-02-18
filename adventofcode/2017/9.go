package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func q1(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	sum := 0
	score := 0
	garbages := 0

	// var groups [][]int
	// var garbages [][]int
	var stack []byte

	top := func() byte {
		if len(stack) == 0 {
			return 0
		}
		return stack[len(stack)-1]
	}

	pop := func() byte {
		t := top()
		stack = stack[:len(stack)-1]
		return t
	}

	push := func(c byte) {
		stack = append(stack, c)
	}

	for i, c := range []byte(input) {
		if top() == '!' {
			pop()
			continue
		}

		if top() == '<' && c != '>' {
			// '!' works inside of < >
			if c == '!' {
				push(c)
			} else {
				garbages += 1
			}
			continue
		}

		switch c {
		case '{':
			score += 1
			sum += score
			push(c)
		case '}':
			score -= 1
			if pop() != '{' {
				fmt.Println("Something wrong here.", i)
			}
		case '>':
			if pop() != '<' {
				fmt.Println("Something wrong here.", i)
			}
		case '<', '!':
			push(c)
		}
	}

	fmt.Println(sum, garbages)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
