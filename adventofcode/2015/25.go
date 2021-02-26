// y is row, x is column
package main

import (
	"fmt"
)

func times(x, y int) int {
	line := x + y - 1
	start := line * (line - 1) / 2
	return start + x - 1
}

func q1(x, y int) int {
	s := 20151125
	for i := 0; i < times(x,y); i ++ {
		s = (s * 252533) % 33554393
	}
	return s
}

func main() {
	fmt.Println(q1(6, 4))
	fmt.Println(q1(2, 6))
	fmt.Println(q1(3, 4))
	fmt.Println(q1(4, 2))
	fmt.Println(q1(3029, 2947))
}
