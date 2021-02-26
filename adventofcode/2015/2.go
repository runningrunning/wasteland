package main

import (
	"bufio"
	"fmt"
	"os"
)

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	sum := 0
	ribbon := 0
	for input.Scan() {
		var w, h, l int
		fmt.Sscanf(input.Text(), "%dx%dx%d", &w, &h, &l)
		sum += 2*w*h + 2*w*l + 2*h*l
		ribbon += w * h * l

		if w*h <= w*l && w*h <= h*l {
			sum += w * h
			ribbon += 2 * (w + h)
		} else 	if w*l <= w*h && w*l <= h*l {
			sum += w * l
			ribbon += 2 * (l + w)
		} else if h*l <= w*l && h*l <= w*h {
			sum += h * l
			ribbon += 2 * (l + h)
		}
	}
	fmt.Println(sum, ribbon)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
