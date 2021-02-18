package main

import (
	"bufio"
	"fmt"
	"os"
)

func severity(d int, layers []int, early bool) int {
	sum := 0
	for i := 0; i < len(layers); i ++ {
		if layers[i] != 0 {
			if layers[i] == 1 {
				sum += i
			} else {
				s := (i + d) % (layers[i] + (layers[i] - 2))
				if s == 0 {
					if early {
						return 1
					}
					sum += layers[i] * i
				}
			}
		}
	}
	return sum
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)
	max := 0
	settings := make(map[int]int)
	for input.Scan() {
		var l, n int
		fmt.Sscanf(input.Text(), "%d: %d", &l, &n)
		settings[l] = n
		max = l
	}

	layers := make([]int, max+1, max+1)

	for l, n := range settings {
		layers[l] = n
	}
	fmt.Println(severity(0, layers, false))

	d := 1

	for severity(d, layers, true) != 0 {
		d += 1
	}

	fmt.Println(d)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
