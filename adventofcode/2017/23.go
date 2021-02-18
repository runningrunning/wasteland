// TODO try to use go concurrent and channel
// be careful about overflow
// Use to use function closure
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Inc struct {
	c string
	x string
	y string
}

func parser(f *os.File) (all []Inc) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		x := strings.Split(input.Text(), " ")
		if len(x) == 3 {
			all = append(all, Inc{x[0], x[1], x[2]})
		} else {
			all = append(all, Inc{x[0], x[1], ""})
		}
	}
	return all
}

type Code struct {
	code      *[]Inc
	pc        int
	registers map[string]int
}

func NewCode(code *[]Inc) func(steps int) bool {
	pc := 0
	registers := make(map[string]int)
	invoked := 0
	// registers["a"] = 0

	values := func(in string) int {
		if len(in) == 1 && in[0] >= 'a' && in[0] <= 'z' {
			return registers[in]
		}
		x, _ := strconv.Atoi(in)
		return x
	}

	return func(steps int) bool {
		times := 0
		for pc < len(*code) && times < steps {
			nxt := 1
			cur := &(*code)[pc]

			switch cur.c {
			case "set":
				registers[cur.x] = values(cur.y)
			case "sub":
				registers[cur.x] -= values(cur.y)
			case "add":
				registers[cur.x] += values(cur.y)
			case "mul":
				invoked++
				registers[cur.x] *= values(cur.y)
			case "mod":
				registers[cur.x] %= values(cur.y)
			case "jgz":
				x := values(cur.x)
				if x > 0 {
					nxt = values(cur.y)
				}
			case "jnz":
				x := values(cur.x)
				if x != 0 {
					nxt = values(cur.y)
				}
			}
			pc += nxt
			times += 1
		}
		if pc >= len(*code) {
			fmt.Println(invoked, registers)
			return true
		}
		return false
	}
}

func q1(f *os.File) {
	code := parser(f)
	p := NewCode(&code)

	for !p(1000) {
	}
}

func test() {
	a := 1

	b := 65
	c := b
	h := 0
	g := 0

	if a != 0 {
		b *= 100
		b += 100000
		c = b
		c += 17000
	}

	sum := 0

	for {

		f := 1
		d := 2

		for {
			e := 2

			for {
				g = d
				g *= e
				sum ++
				if g-b == 0 {
					f = 0
				}
				e += 1
				g = e
				if g-b == 0 {
					break
				}
			}
			d += 1
			g = d
			if g-b == 0 {
				break
			}
		}

		if f == 0 {
			h += 1
		}
		g = b
		g -= c
		if g == 0 {
			break
		}
		b += 17
	}

	fmt.Println(h, sum)
}

// set b 65
// set c b
// jnz a 2
// jnz 1 5
// mul b 100
// sub b -100000
// set c b
// sub c -17000
// set f 1
// set d 2
// set e 2
// set g d
// mul g e
// sub g b
// jnz g 2
// set f 0
// sub e -1
// set g e
// sub g b
// jnz g -8
// sub d -1
// set g d
// sub g b
// jnz g -13
// jnz f 2
// sub h -1
// set g b
// sub g c
// jnz g 2
// jnz 1 3
// sub b -17
// jnz 1 -23


func test2() {
	b := 65
	c := b
	h, g := 0, 0
	b *= 100
	b += 100000
	c = b
	c += 17000
	for {
		f := 1
		d := 2
		for {
			if b % d == 0 {
				f = 0
			}
			d += 1
			g = d
			if g - b == 0 {
				break
			}
		}
		if f == 0 {
			h += 1
		}
		g = b
		g -= c
		if g == 0 {
			break
		}
		b += 17
	}
	fmt.Println(h)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	test2()
}
