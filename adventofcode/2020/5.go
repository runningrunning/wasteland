package main

import (
	"bufio"
	"fmt"
	"os"
)

func seat(s string) int {
	num := 0
	bits := 1
	for i := 9; i >= 0; i-- {
		if s[i] == 'R' || s[i] == 'B' {
			num += bits
		}
		bits *= 2
	}
	return num
}

func q1(f *os.File) {
	high := 0
	input := bufio.NewScanner(f)
	for input.Scan() {
		if len(input.Text()) < 9 {
			break
		}
		cur := seat(input.Text())
		if high < cur {
			high = cur
		}
	}
	fmt.Println(high)
}

func q2(f *os.File) int {
	high := 0
	low := 0xffffff
	all := 0
	input := bufio.NewScanner(f)
	for input.Scan() {
		if len(input.Text()) < 9 {
			break
		}

		cur := seat(input.Text())

		if high < cur {
			high = cur
		}

		if low > cur {
			low = cur
		}

		all += cur
	}
	return (low + high) * (high - low + 1) / 2 - all
}

func main() {
	f, _ := os.Open(os.Args[1])
	q1(f)
	f.Seek(0, 0)
	fmt.Println(q2(f))
	f.Close()
}
