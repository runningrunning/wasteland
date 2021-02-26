// Can not use Bisection metho, as it's not linear
// 831600: 36902400
// 831500: 18170880
// 831800: 19344000
package main

import (
	"fmt"
	"math"
)

func sqrt(i int) int {
	return int(math.Ceil(math.Sqrt(float64(i))))
}

func num(i int) int {
	x := 1

	sum := 0
	for {
		if i < x * x {
			break
		}

		if i % x == 0 {
			sum += x

			if i != x * x {
				sum += i / x
			}
		}
		x ++
	}
	return sum * 10
}

func q1(min int) int {
	x := 10000
	for {
		sum := 0
		for i := 1; i <= sqrt(x); i++ {
			if (x % i) == 0 {
				sum += i
				if x != i*i {
					sum += x / i
				}
			}

			if sum * 10 >= min {
				return x
			}
		}
		x ++
	}
	return -1
}

func q2(min int) int {
	x := 831600

	for {
		sum := 0
		for i := 1; i <= 50; i ++ {
			if (x % i) == 0 {
				sum += x / i
			}
		}

		if sum * 11 >= min {
			return x
		}
		x ++
	}
	return -1
}

func main() {
	fmt.Println(q1(36000000))
	fmt.Println(q2(36000000))
}
