package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var reader *bufio.Reader

func round(p1, p2 []int) ([]int, []int) {
	if p1[0] > p2[0] {
		return append(p1[1:], p1[0], p2[0]), p2[1:]
	}
	return p1[1:], append(p2[1:], p2[0], p1[0])
}

func score(p []int) int {
	sum := 0
	for i, x := range p {
		sum += x * (len(p) - i)
	}
	return sum
}

func parser(f *os.File) ([]int, []int) {
	var p1, p2 []int
	first := true
	input := bufio.NewScanner(f)

	for input.Scan() {
		s := input.Text()

		if len(s) == 0 {
			continue
		}

		if s == "Player 1:" {
			first = true
		} else if s == "Player 2:" {
			first = false
		} else {
			n, _ := strconv.Atoi(s)
			if first {
				p1 = append(p1, n)
			} else {
				p2 = append(p2, n)
			}
		}
	}
	fmt.Println(p1, p2)
	return p1, p2
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}

	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func q1(f *os.File) {
	p1, p2 := parser(f)
	for len(p1) != 0 && len(p2) != 0 {
		p1, p2 = round(p1, p2)
	}
	fmt.Println(score(p1), score(p2))
}

func round2(p1, p2 []int, id int) ([]int, []int) {

	var h1, h2 [][]int

	for {
		fmt.Println("=================================", id)
		fmt.Println(p1)
		fmt.Println(p2)
		fmt.Println("=================END================")

		// reader.ReadString('\n')

		if len(p1) == 0 {
			return nil, p2
		}

		if len(p2) == 0 {
			return p1, nil
		}

		// samve as before, p1, win
		for _, h := range h1 {
			if equal(h, p1) {
				return p1, nil
			}
		}

		for _, h := range h2 {
			if equal(h, p2) {
				return p1, nil
			}
		}

		h1 = append(h1, p1)
		h2 = append(h2, p2)

		t1 := p1[0]
		t2 := p2[0]

		if t1 <= len(p1[1:]) && t2 <= len(p2[1:]) {
			n1 := make([]int, t1)
			n2 := make([]int, t2)
			copy(n1, p1[1:])
			copy(n2, p2[1:])

			n1, n2 = round2(n1, n2, id + 1)

			if len(n1) != 0 {
				p1 = append(p1[1:], p1[0], p2[0])
				p2 = p2[1:]
			} else {
				// becareful, must append p1 before removing its head
				p2 = append(p2[1:], p2[0], p1[0])
				p1 = p1[1:]
			}
		} else {
			p1, p2 = round(p1, p2)
		}
	}
}

func q2(f *os.File) {
	p1, p2 := parser(f)

	p1, p2 = round2(p1, p2, 1)

	fmt.Println(score(p1), score(p2))
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
