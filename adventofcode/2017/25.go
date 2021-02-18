package main

import (
	"fmt"
)

func state(w0, m0 int, s0 string, w1, m1 int, s1 string) func(int) (int, int, string) {
	return func(value int) (int, int, string) {
		if value == 0 {
			return w0, m0, s0
		}
		return w1, m1, s1
	}
}

// right 1, left -1
func q1() {
	machine := make(map[string]func(int) (int, int, string))

	steps := 12302209

	machine["A"] = state(1, 1, "B", 0, -1, "D")

	machine["B"] = state(1, 1, "C", 0, 1, "F")

	machine["C"] = state(1, -1, "C", 1, -1, "A")

	machine["D"] = state(0, -1, "E", 1, 1, "A")

	machine["E"] = state(1, -1, "A", 0, 1, "B")

	machine["F"] = state(0, 1, "C", 0, 1, "E")

	checksums := make(map[int]int)

	x := 0
	cur := "A"

	for i := 0; i < steps; i++ {
		v, d, n := machine[cur](checksums[x])
		checksums[x] = v
		x += d
		cur = n
	}

	sum := 0
	for _, x := range checksums {
		if x == 1 {
			sum++
		}
	}

	fmt.Println(sum)
}

func main() {
	q1()
}
