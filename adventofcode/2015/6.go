// Do it in simpler way
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	n := 1000
	lights := make([][]int, n, n)
	for i := 0; i < n; i++ {
		lights[i] = make([]int, n, n)
	}

	// q1
	do := func(x1, y1, x2, y2, s int) {
		for x1 <= x2 {
			for t := y1; t <= y2; t++ {
				if s < 2 {
					lights[x1][t] = s
				} else {
					lights[x1][t] = (lights[x1][t] + 1) % 2
				}
			}
			x1++
		}
	}


	// q2
	// do := func(x1, y1, x2, y2, s int) {
	// 	if s == 0 {
	// 		s = -1
	// 	}

	// 	for x1 <= x2 {
	// 		for t := y1; t <= y2; t++ {
	// 			lights[x1][t] += s
	// 			if lights[x1][t] < 0 {
	// 				lights[x1][t] = 0
	// 			}
	// 		}
	// 		x1++
	// 	}
	// }

	on := func(x1, y1, x2, y2 int) {
		do(x1, y1, x2, y2, 1)
	}

	off := func(x1, y1, x2, y2 int) {
		do(x1, y1, x2, y2, 0)
	}

	rev := func(x1, y1, x2, y2 int) {
		do(x1, y1, x2, y2, 2)
	}

	count := func() int {
		sum := 0
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				sum += int(lights[i][j])
			}
		}
		return sum
	}

	var x1, y1, x2, y2 int

	for input.Scan() {
		ws := strings.Split(input.Text(), " ")
		switch ws[0] {
		case "turn":
			fmt.Sscanf(ws[2], "%d,%d", &x1, &y1)
			fmt.Sscanf(ws[4], "%d,%d", &x2, &y2)
			if ws[1] == "on" {
				on(x1, y1, x2, y2)
			} else {
				off(x1, y1, x2, y2)
			}
		case "toggle":
			fmt.Sscanf(ws[1], "%d,%d", &x1, &y1)
			fmt.Sscanf(ws[3], "%d,%d", &x2, &y2)
			rev(x1, y1, x2, y2)
		}
	}

	fmt.Println(count())
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
