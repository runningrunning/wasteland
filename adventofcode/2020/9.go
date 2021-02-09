package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func q1(f *os.File, p int) int {
	num := 0
	input := bufio.NewScanner(f)
	numbers := make(map[int]bool)
	current := make([]int, p)

	for input.Scan() {
		if len(input.Text()) == 0 {
			break
		}

		x, _ := strconv.Atoi(input.Text())

		if num < p {
			current[num] = x
		} else {
			found := false

			for _, n := range current {
				if (x-n) != n && numbers[x-n] {
					found = true
					break
				}
			}

			if !found {
				fmt.Println(x)
				return x
			}

			d := current[num%p]
			numbers[d] = false
			current[num%p] = x
		}

		numbers[x] = true
		num++
	}
	return 0
}

func q2(f *os.File, n int) {
	s := 0
	cur := 0

	var numbers []int
	input := bufio.NewScanner(f)

	for input.Scan() {
		if len(input.Text()) == 0 {
			break
		}

		x, _ := strconv.Atoi(input.Text())
		cur += x
		numbers = append(numbers, x)

		for cur > n {
			if s == len(numbers)+1 {
				break
			}
			cur -= numbers[s]
			s++
		}

		if cur == n {
			break
		}
	}

	min := n
	max := 0

	for s < len(numbers) {
		if numbers[s] < min {
			min = numbers[s]
		}

		if numbers[s] > max {
			max = numbers[s]
		}
		s++
	}

	fmt.Println(max + min)
}

func main() {
	f, _ := os.Open(os.Args[1])
	x := q1(f, 25)
	f.Seek(0, 0)
	q2(f, x)
	f.Close()
}
