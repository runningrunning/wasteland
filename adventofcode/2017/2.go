package main

import (
	"bufio"
	"fmt"
	"strconv"
	"strings"
	"os"
)


func q1(f *os.File) {
	input := bufio.NewScanner(f)
	sum := 0
	for input.Scan() {
		min, max := 10000, -10000
		for _, in := range strings.Split(strings.TrimSpace(input.Text()), "\t") {
			x, _ := strconv.Atoi(in)

			if x < min {
				min = x
			}

			if x > max {
				max = x
			}
		}

		sum += max - min
	}

	fmt.Println(sum)
}

func q2(f *os.File) {
	input := bufio.NewScanner(f)
	sum := 0
	for input.Scan() {
		var all []int
		for _, in := range strings.Split(strings.TrimSpace(input.Text()), "\t") {
			x, _ := strconv.Atoi(in)
			for _, y := range all {
				a, b := x, y

				if a < b {
					a, b = b, a
				}

				if (a % b) == 0 {
					sum += a / b
				}
			}
			all = append(all, x)
		}
	}

	fmt.Println(sum)
}


func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
