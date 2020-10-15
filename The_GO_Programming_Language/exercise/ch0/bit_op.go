package main

import (
	"fmt"
)

func main() {
	var x uint8 = 1<<1 | 1<<5
	var y uint8 = 1<<1 | 1<<2

	fmt.Printf("x %08b\n", x)
	fmt.Printf("y %08b\n", y)

	fmt.Printf("x&y %08b\n", x&y)
	fmt.Printf("x|y %08b\n", x|y)
	fmt.Printf("x^y %08b\n", x^y)
	fmt.Printf("x&^y %08b\n", x&^y)
}
