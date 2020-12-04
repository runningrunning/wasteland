package main

import (
	"bufio"
	"fmt"
	"os"
)

func q1(f *os.File) {
	valid := 0
	input := bufio.NewScanner(f)
	for input.Scan() {
		var (
			min, max int
			ch byte
			password string
		)

		fmt.Sscanf(input.Text(), "%d-%d %c: %s", &min, &max, &ch, &password)

		num := 0
		for _, c := range []byte(password) {
			if c == ch {
				num ++
			}
		}

		if num >= min && num <= max {
			valid ++
		}
	}
	fmt.Printf("q1 valid is %v.\n", valid)
}

func q2(f *os.File) {
	valid := 0
	input := bufio.NewScanner(f)
	for input.Scan() {
		var (
			min, max int
			ch byte
			password string
		)

		fmt.Sscanf(input.Text(), "%d-%d %c: %s", &min, &max, &ch, &password)

		num := 0
		bs := []byte(password)

		if min <= len(bs) {
			if bs[min - 1] == ch {
				num += 1
			}
		}

		if max <= len(bs) {
			if bs[max - 1] == ch {
				num += 1
			}
		}

		if num == 1 {
			valid ++
		}

	}
	fmt.Printf("q2 valid is %v.\n", valid)
}

func main() {
	f, _ := os.Open(os.Args[1:][0])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
