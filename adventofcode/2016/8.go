package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func output(d [][]byte) {
	for _, l := range d {
		fmt.Println(string(l))
	}
	fmt.Println()
}

func count(d [][]byte) int {
	sum := 0
	for _, l := range d {
		for _, c := range l {
			if c == '#' {
				sum++
			}
		}
	}

	return sum
}

func display(r, c int) [][]byte {
	t := make([][]byte, r, r)
	for i := 0; i < r; i++ {
		t[i] = make([]byte, c, c)

		for j := 0; j < c; j++ {
			t[i][j] = byte('.')
		}
	}
	return t
}

func rect(d [][]byte, x, y int) {
	for i := 0; i < y && i < len(d); i++ {
		for j := 0; j < x && j < len(d[i]); j++ {
			d[i][j] = '#'
		}
	}
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func rotateX(d [][]byte, x, o int) {
	l := len(d)
	o %= l
	for i := 0; i < gcd(l, o); i++ {
		n := (i + o) % l
		t := d[i][x]
		for {
			t, d[n][x] = d[n][x], t
			if n == i {
				break
			}
			n = (n + o) % l
		}
	}
}

func rotateY(d [][]byte, y, o int) {
	l := len(d[0])
	o %= l

	for i := 0; i < gcd(l, o); i++ {
		n := (i + o) % l
		t := d[y][i]
		for {
			t, d[y][n] = d[y][n], t
			if n == i {
				break
			}
			n = (n + o) % l
		}
	}
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)
	d := display(6, 50)

	for input.Scan() {
		t := input.Text()

		if strings.HasPrefix(t, "rect") {
			var x, y int
			if n, err := fmt.Sscanf(t, "rect %dx%d", &x, &y); err != nil || n != 2 {
				fmt.Errorf("Scan error.\n")
				os.Exit(1)
			}
			rect(d, x, y)
		} else if strings.HasPrefix(t, "rotate row") {
			var y, o int
			if n, err := fmt.Sscanf(t, "rotate row y=%d by %d", &y, &o); err != nil || n != 2 {
				fmt.Errorf("Scan error.\n")
				os.Exit(1)
			}
			rotateY(d, y, o)
		} else if strings.HasPrefix(t, "rotate column") {
			var x, o int
			if n, err := fmt.Sscanf(t, "rotate column x=%d by %d", &x, &o); err != nil || n != 2 {
				fmt.Errorf("Scan error.\n")
				os.Exit(1)
			}
			rotateX(d, x, o)
		}
	}

	fmt.Println(count(d))
	output(d)
}

func test() {
	d := display(3, 7)
	output(d)
	rect(d, 3, 2)
	output(d)
	rotateX(d, 1, 1)
	output(d)
	rotateY(d, 0, 4)
	output(d)
	rotateX(d, 1, 1)
	output(d)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
