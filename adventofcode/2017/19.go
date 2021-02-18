// keep it simpler
package main

import (
	"bufio"
	"fmt"
	"os"
)

func q1(f *os.File) {
	var route []string
	input := bufio.NewScanner(f)
	for input.Scan() {
		route = append(route, input.Text())
	}

	r, w := len(route), len(route[0])
	x, y := 0, 0

	for y = 0; y < w; y++ {
		if route[x][y] == '|' {
			break
		}
	}

	px, py := x-1, y

	var steps int
	var path string

	for {
		steps += 1
		c := route[x][y]
		switch c {
		case ' ':
			fmt.Println(path, steps-1)
			return
		case '+':
			if x > 0 && ((x-1) != px || y != py) && route[x-1][y] != ' ' {
				px, py, x, y = x, y, x-1, y
			} else if y > 0 && ((y-1) != py || x != px) && route[x][y-1] != ' ' {
				px, py, x, y = x, y, x, y-1
			} else if x < r-1 && ((x+1) != px || y != py) && route[x+1][y] != ' ' {
				px, py, x, y = x, y, x+1, y
			} else if y < w-1 && ((y+1) != py || x != px) && route[x][y+1] != ' ' {
				px, py, x, y = x, y, x, y+1
			} else {
				fmt.Println("Wrong route.")
			}
		default:
			if c >= 'A' && c <= 'Z' {
				path += string(c)
			}
			px, py, x, y = x, y, x+x-px, y+y-py
		}
	}

}

func main() {
	f, _ := os.Open(os.Args[1])
	q1(f)
}
