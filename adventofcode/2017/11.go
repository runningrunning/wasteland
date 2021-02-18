package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func steps(x, y int) int {
	if x < 0 {
		x = -x
	}

	if y < 0 {
		y = -y
	}

	min_x := (x + 1) / 2
	min_y := y / 2

	if min_x > min_y {
		return min_x
	}
	return min_y
}

func q1(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	max := 0
	x, y := 0, 0
	for _, c := range strings.Split(input, ",") {
		switch c {
		case "n":
			x += 2
		case "s":
			x -= 2
		case "nw":
			x += 1
			y -= 2
		case "ne":
			x += 1
			y += 2
		case "sw":
			x -= 1
			y -= 2
		case "se":
			x -= 1
			y += 2
		}

		st := steps(x, y)
		if st > max {
			max = st
		}
	}

	fmt.Println(steps(x, y), max)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
