package main

import (
	"fmt"
)


func loop(in, s int) int {
	in *= s
	return in % 20201227
}

func q1(a, b int) {
	in := 1
	ai, bi := 0, 0

	for in != a {
		in = loop(in, 7)
		ai ++
	}

	in = 1

	for in != b {
		in = loop(in, 7)
		bi ++
	}
	fmt.Println(ai, bi)

	in = 1
	for i := 0; i < ai; i ++ {
		in = loop(in, b)
	}

	fmt.Println(in)

	in = 1
	for i := 0; i < bi; i ++ {
		in = loop(in, a)
	}
	fmt.Println(in)
}

func main() {
	// q1(5764801, 17807724)
	q1(15628416, 11161639)
}
