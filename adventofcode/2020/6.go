package main

import (
	"bufio"
	"fmt"
	"os"
)

func q1(f *os.File) {
	sum := 0
	input := bufio.NewScanner(f)
	flag := [26]int{0}
	for input.Scan() {
		if len(input.Text()) == 0 {
			flag = [26]int{0}
			continue
		}

		for _, c := range input.Text() {
			if flag[c-'a'] == 0 {
				flag[c-'a'] = 1
				sum++
			}
		}
	}
	fmt.Println(sum)
}

func q2(f *os.File) {
	sum := 0
	input := bufio.NewScanner(f)
	line := 0
	flag := [26]int{0}

	for input.Scan() {
		if len(input.Text()) == 0 {
			for _, n := range flag {
				if line != 0 && n == line {
					sum++
				}
			}

			line = 0
			flag = [26]int{0}
			continue
		}

		for _, c := range input.Text() {
			flag[c-'a']++
		}
		line++
	}

	for _, n := range flag {
		if line != 0 && n == line {
			sum++
		}
	}
	fmt.Println(sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
