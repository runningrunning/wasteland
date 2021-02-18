package main

import (
	"fmt"
)

func q1(a, b, n int) {
	sum := 0
	mask := (1 << 16) - 1
	for i := 0; i < n; i++ {
		a *= 16807
		b *= 48271
		a %= 2147483647
		b %= 2147483647

		if (a & mask) == (b & mask) {
			sum += 1
		}
	}

	fmt.Println(sum)
}

func q2(a, b, n int) {
	sum := 0
	mask := (1 << 16) - 1

	for i := 0; i < n; i++ {
		for {
			a *= 16807
			a %= 2147483647
			if (a & 3) == 0 {
				break
			}
		}

		for {
			b *= 48271
			b %= 2147483647
			if (b & 7) == 0 {
				break
			}
		}
		if (a & mask) == (b & mask) {
			sum += 1
		}
	}
	fmt.Println(sum)
}

func main() {
	// q1(65, 8921, 5)
	// q2(65, 8921, 1056)
	q1(722, 354, 40000000)
	q2(722, 354, 5000000)
}
