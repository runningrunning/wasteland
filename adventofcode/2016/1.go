package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func distance(x, y int) int {
	if x < 0 {
		x = -x
	}

	if y < 0 {
		y = -y
	}

	return x + y
}

func q1(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	history := make(map[int]map[int]bool)

	x, y, face := 0, 0, 0
	directions := [][]int {[]int{1, 0}, []int{0, 1}, []int{-1,0}, []int{0,-1}}

	for _, inc := range strings.Split(input, ", ") {
		if inc[0] == 'R' {
			face = (face + 1) % len(directions)
		} else {
			face = (face - 1 + len(directions)) % len(directions)
		}
		n, _ := strconv.Atoi(inc[1:])
		for i := 1; i <= n ; i ++ {
			x, y = x + directions[face][0], y + directions[face][1]
			if history[x] == nil {
				history[x] = make(map[int]bool)
			}
			if (history[x][y]) {
				fmt.Println(distance(x,y))
				return
			}
			history[x][y] = true
		}
	}

	fmt.Println(distance(x, y))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
