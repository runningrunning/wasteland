// Find better solution ?
package main

import "fmt"
func q1(l int) int {
	i := 0
	id := 0
	left := 0

	for l > 1 {
		if l&1 == 1 {
			if left == 0 {
				left = 1
				l >>= 1
				l += 1
			} else {
				left = 0
				id |= 1 << i
				l >>= 1
			}
		} else {
			if left == 1 {
				id |= 1 << i
				l >>= 1
			} else {
				l >>= 1
			}
		}
		i += 1
	}
	return id + 1
}

func q2(l int) int {
	s := make([]int, l, l)
	for i := 0; i < l; i ++ {
		s[i] = i + 1
	}

    pi := int(l & 1)
	pattern := []int{0, 0, 1}

	st := l / 2
	left := l
	for left != 1 {
		if s[st] != 0 {
			if pattern[pi%3] == 0 {
				s[st] = 0
				left --
			}
			pi ++
		}
		st = (st + 1) % l
	}

	for _, c := range s {
		if c != 0 {
			return c
		}
	}
	return -1
}

func main() {
	fmt.Println(q1(3017957))
	fmt.Println(q1(5))
	fmt.Println(q1(6))
	fmt.Println(q2(3017957))
	fmt.Println(q2(5))
	fmt.Println(q2(6))
}
