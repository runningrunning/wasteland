package main

import (
	"bufio"
	"fmt"
	"os"
)

func q1(f *os.File) {
	input := bufio.NewScanner(f)

	d := []rune{'E', 'S', 'W', 'N'}

	a, x, y := 0, 0, 0
	for input.Scan() {
		if len(input.Text()) == 0 {
			break
		}

		c := 'F'
		n := 0
		fmt.Sscanf(input.Text(), "%c%d", &c, &n)

		if c == 'F' {
			c = d[a]
		}

		switch c {
		case 'L':
			a = (a - n/90 + 4) % 4
		case 'R':
			a = (a + n/90 + 4) % 4
		case 'E':
			x += n
		case 'S':
			y -= n
		case 'W':
			x -= n
		case 'N':
			y += n
		}
	}

	fmt.Println(x)
	fmt.Println(y)

	if x < 0 {
		x = -x
	}

	if y < 0 {
		y = -y
	}

	fmt.Println(x + y)
}

func q2(f *os.File) {
	input := bufio.NewScanner(f)
	x, y, wx, wy := 0, 0, 10, 1

	for input.Scan() {
		if len(input.Text()) == 0 {
			break
		}

		c := 'F'
		n := 0
		fmt.Sscanf(input.Text(), "%c%d", &c, &n)

		switch c {
		case 'F':
			x += n * wx
			y += n * wy
		case 'E':
			wx += n
		case 'S':
			wy -= n
		case 'W':
			wx -= n
		case 'N':
			wy += n
		case 'L':
			switch n / 90 {
			case 1:
				wx, wy = -wy, wx
			case 2:
				wx, wy = -wx, -wy
			case 3:
				wx, wy = wy, -wx
			}

		case 'R':
			switch n / 90 {
			case 1:
				wx, wy = wy, -wx
			case 2:
				wx, wy = -wx, -wy
			case 3:
				wx, wy = -wy, wx
			}
		}
	}

	fmt.Println(x)
	fmt.Println(y)

	if x < 0 {
		x = -x
	}

	if y < 0 {
		y = -y
	}

	fmt.Println(x + y)
}

func main() {
	f, _ := os.Open(os.Args[1])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
