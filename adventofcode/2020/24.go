package main

import (
	"bufio"
	"fmt"
	"os"
)

type Tile struct {
	x, y int
}

func (t Tile) e() Tile {
	t.x += 2
	return t
}

func (t Tile) se() Tile {
	t.x += 1
	t.y -= 3
	return t
}

func (t Tile) sw() Tile {
	t.x -= 1
	t.y -= 3
	return t
}

func (t Tile) w() Tile {
	t.x -= 2
	return t
}

func (t Tile) ne() Tile {
	t.x += 1
	t.y += 3
	return t
}

func (t Tile) nw() Tile {
	t.x -= 1
	t.y += 3
	return t
}

func hash(t Tile) int {
	return (t.x << 16) + t.y
}

func path(p string) Tile {
	t := Tile{x: 10000, y: 10000}

	for i := 0; i < len(p); i++ {
		switch p[i] {
		case 'e':
			t = t.e()
		case 's':
			i++
			if p[i] == 'e' {
				t = t.se()
			} else {
				t = t.sw()
			}
		case 'w':
			t = t.w()
		case 'n':
			i++
			if p[i] == 'e' {
				t = t.ne()
			} else {
				t = t.nw()
			}
		default:
			fmt.Println("Error here")
		}
	}

	fmt.Println(t)

	return t
}

func p1(f *os.File) {
	input := bufio.NewScanner(f)
	cache := make(map[int]int)
	for input.Scan() {
		index := hash(path(input.Text()))
		cache[index] = 1 - cache[index]
	}
	output(cache)
}

func output(in map[int]int) {
	sum := 0
	for _, x := range in {
		if x == 1 {
			sum++
		}
	}
	fmt.Println(sum)
}

func around(t Tile, s map[int]int) int {
	return s[hash(t.e())] +
		s[hash(t.w())] +
		s[hash(t.se())] +
		s[hash(t.sw())] +
		s[hash(t.ne())] +
		s[hash(t.nw())]
}

func round(s map[int]int) map[int]int {
	next := make(map[int]int)

	for h, x := range s {
		if x == 1 {
			t := Tile{x:h>>16, y:h&0xffff}
			num := around(t, s)
			if num == 1 || num == 2 {
				next[h] = 1
			}

			if s[hash(t.e())] == 0 {
				num = around(t.e(), s)
				if num == 2 {
					next[hash(t.e())] = 1
				}
			}

			if s[hash(t.w())] == 0 {
				num = around(t.w(), s)
				if num == 2 {
					next[hash(t.w())] = 1
				}
			}

			if s[hash(t.se())] == 0 {
				num = around(t.se(), s)
				if num == 2 {
					next[hash(t.se())] = 1
				}
			}

			if s[hash(t.sw())] == 0 {
				num = around (t.sw(), s)
				if num == 2 {
					next[hash(t.sw())] = 1
				}
			}

			if s[hash(t.ne())] == 0 {
				num = around(t.ne(), s)
				if num == 2 {
					next[hash(t.ne())] = 1
				}
			}

			if s[hash(t.nw())] == 0 {
				num = around(t.nw(), s)
				if num == 2 {
					next[hash(t.nw())] = 1
				}
			}
		}
	}
	return next
}

func p2(f *os.File) {
	input := bufio.NewScanner(f)
	cache := make(map[int]int)
	for input.Scan() {
		t := path(input.Text())
		index := hash(t)
		cache[index] = 1 - cache[index]
	}

	status := cache
	output(cache)

	for i := 0; i < 100; i ++ {
		status = round(status)
		fmt.Print(i+1, ":")
		output(status)
	}
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	p1(f)
	f.Seek(0,0)
	p2(f)
}
