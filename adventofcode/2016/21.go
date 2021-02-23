package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Ins struct {
	cmd  string
	x, y int
}

func parser(f *os.File) (all []Ins) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)
	var ws []string

	toInt := func(i int) int {
		n, _ := strconv.Atoi(ws[i])
		return n
	}

	for input.Scan() {
		ws = strings.Split(input.Text(), " ")
		s := Ins{cmd: ws[0] + ws[1]}
		switch ws[0] + ws[1] {
		case "swapposition":
			s.x, s.y = toInt(2), toInt(5)
		case "swapletter":
			s.x, s.y = int(ws[2][0]), int(ws[5][0])
		case "rotateleft":
			s.x = toInt(2)
		case "rotateright":
			s.x = toInt(2)
		case "rotatebased":
			s.x = int(ws[6][0])
		case "reversepositions":
			s.x, s.y = toInt(2), toInt(4)
		case "moveposition":
			s.x, s.y = toInt(2), toInt(5)
		default:
			fmt.Errorf("Something in the inputs.\n")
		}

		all = append(all, s)
	}
	return
}

func apply(all []Ins, s string, r bool) string {
	t := []byte(s)

	indexOf := func(c byte) int {
		for i := 0; i < len(t); i++ {
			if t[i] == c {
				return i
			}
		}
		fmt.Println("Something wrong, can not find index of %c in %s.\n", c, s)
		return -1
	}

	// only do it rotate right 1
	rotate := func() {
		x := t[0]
		for i := 1; i < len(t); i++ {
			x, t[i] = t[i], x
		}
		t[0] = x
	}

	reverse := func(x, y int) {
		for i, j := x, y; i < j; i, j = i+1, j-1 {
			t[i], t[j] = t[j], t[i]
		}
	}

	remove := func(x int) byte {
		b := t[x]
		for i := x; i < len(t)-1; i++ {
			t[i] = t[i+1]
		}
		return b
	}

	insert := func(x int, b byte) {
		for i := len(t) - 1; i > x; i-- {
			t[i] = t[i-1]
		}
		t[x] = b
	}

	base := func(x int) int {
		if x >= 4 {
			x++
		}
		x++
		return x % len(t)
	}

	cur, step := 0, 1
	end := len(all)

	if r {
		cur, step, end = end - 1, -1, cur -1
	}

	for k := cur; k != end; k = k + step {
		i := all[k]
		switch i.cmd {
		case "swapposition":
			t[i.x], t[i.y] = t[i.y], t[i.x]
		case "swapletter":
			x := indexOf(byte(i.x))
			y := indexOf(byte(i.y))
			t[x], t[y] = t[y], t[x]
		case "rotateleft":
			x := i.x % len(t)
			x = (-x + len(t)) % len(t)

			if r {
				x = len(t) - x
			}

			for j := 0; j < x; j++ {
				rotate()
			}
		case "rotateright":
			x := i.x % len(t)

			if r {
				x = len(t) - x
			}

			for j := 0; j < x; j++ {
				rotate()
			}
		case "rotatebased":
			x := indexOf(byte(i.x))
			if r {
				pre := -1
				for p := 0; p < len(t); p++ {
					if (p+base(p))%len(t) == x {
						if pre != -1 {
							fmt.Println("2 possible answer here.\n", pre, p)
						}
						pre = p
					}
				}
				x = (pre - x + len(t)) % len(t)
				for j := 0; j < x; j++ {
					rotate()
				}

			} else {
				for j := 0; j < base(x); j++ {
					rotate()
				}
			}
		case "reversepositions":
			reverse(i.x, i.y)
		case "moveposition":
			if r {
				insert(i.x, remove(i.y))
			} else {
				insert(i.y, remove(i.x))
			}
		}
		// fmt.Println(i.cmd, string(t))
	}
	return string(t)
}

func q1(f *os.File, s string) {
	fmt.Println(s, "is", apply(parser(f), s, false))
}

func q2(f *os.File, s string) {
	fmt.Println(s, "is", apply(parser(f), s, true))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	// q1(f, "abcde")
	// q1(f, "deabc")
	// q2(f, "decab")
	q1(f, "abcdefgh")
	q2(f, "fbgdceah")
	q1(f, "afhdbegc")
}
