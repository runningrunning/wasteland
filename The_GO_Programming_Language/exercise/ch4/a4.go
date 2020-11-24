package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func Gcd(a, b int) int {
	if a >= b {
		return gcd(a, b)
	}
	return gcd(b, a)
}

// +r => -r <=
func rotateIntOnePass(s []int, r int) []int {
	l := len(s)

	var x = Gcd(int(math.Abs(float64(r))), l)

	r = r % l

	if r == 0 {
		return s
	}

	next := func(i, r int) int {
		return (i + r + l) % l
	}

	for i := 0; i < x; i++ {
		st := i
		sv := s[st]
		nx := next(st, r)
		for i != nx {
			s[st] = s[nx]
			st, nx = nx, next(nx, r)
		}
		s[st] = sv
	}
	return s
}

func rotateIntNewSlice(s []int, r int) []int {
	l := len(s)
	r %= l
	ns := make([]int, l)

	for i, v := range s {
		ns[(i+r+l)%l] = v
	}
	return ns
}

func rotateInt(s []int, r int) []int {
	// return rotateIntOnePass(s, r)
	return rotateIntNewSlice(s, r)
}

func main() {
	s := [13]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
	a := s[:]
	for i := 0; i <= len(a); i++ {
		// fmt.Println(a)
		fmt.Println(rotateInt(a, -i))
		fmt.Println(rotateInt(a, i))
	}
	// fmt.Println(a)
}
