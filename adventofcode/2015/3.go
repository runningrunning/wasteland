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

	visited := make(map[int]int)

	// start points
	starter := []int{10000, 10000, 10000, 10000}

	hash := func(x, y int) int { return y<<16 | x }
	visit := func(x, y int) { visited[hash(x, y)]++ }

	for i := 0; i < len(starter); i += 2 {
		visit(starter[i], starter[i+1])
	}

	i := 0
	for _, c := range input {
		x, y := starter[i%len(starter)], starter[i%len(starter)+1]
		switch c {
		case '^':
			y -= 1
		case 'v':
			y += 1
		case '>':
			x += 1
		case '<':
			x -= 1
		}
		visit(x, y)
		starter[i%len(starter)], starter[i%len(starter)+1] = x, y
		i += 2
	}

	fmt.Println(len(visited))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
