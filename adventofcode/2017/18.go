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
	rcv, snd  []int
}

func NewCode(code *[]Inc, p int, input, output *[]int) func(steps int) (bool, int) {
	pc := 0
	send := 0
	registers := make(map[string]int)
	registers["p"] = p

	values := func(in string) int {
		if len(in) == 1 && in[0] >= 'a' && in[0] <= 'z' {
			return registers[in]
		}
		x, _ := strconv.Atoi(in)
		return x
	}

	return func(steps int) (bool, int) {
		times := 0
		for pc < len(*code) && times < steps {
			nxt := 1
			cur := &(*code)[pc]

			switch cur.c {
			case "snd":
				send += 1
				*output = append(*output, values(cur.x))
				fmt.Println(p, "Send ", values(cur.x))
			case "set":
				registers[cur.x] = values(cur.y)
			case "add":
				registers[cur.x] += values(cur.y)
			case "mul":
				registers[cur.x] *= values(cur.y)
			case "mod":
				registers[cur.x] %= values(cur.y)
			case "rcv":
				if len(*input) == 0 {
					return true, send
				}
				registers[cur.x] = (*input)[0]
				*input = (*input)[1:]
				fmt.Println(p, "Recv ", registers[cur.x])
			case "jgz":
				x := values(cur.x)
				if x > 0 {
					nxt = values(cur.y)
				}
			}

			pc += nxt
			times += 1
		}

		if pc >= len(*code) {
			return true, send
		}
		return false, send
	}
}

func q1(f *os.File) {
	pc := 0
	all := parser(f)

	sound := make([]int, 0, 10)
	registers := make(map[string]int)

	values := func(in string) int {
		if len(in) == 1 && in[0] >= 'a' && in[0] <= 'z' {
			return registers[in]
		}
		x, _ := strconv.Atoi(in)
		return x
	}

	for pc < len(all) {
		nxt := 1
		cur := &all[pc]

		switch cur.c {
		case "snd":
			sound = append(sound, values(cur.x))
			fmt.Println("Play ", sound[len(sound)-1])
		case "set":
			registers[cur.x] = values(cur.y)
		case "add":
			registers[cur.x] += values(cur.y)
		case "mul":
			registers[cur.x] *= values(cur.y)
		case "mod":
			registers[cur.x] %= values(cur.y)
		case "rcv":
			x := values(cur.x)
			if x != 0 {
				fmt.Println("Rcv ", sound[len(sound)-1])
				return
			}
		case "jgz":
			x := values(cur.x)
			if x > 0 {
				nxt = values(cur.y)
			}
		}
		pc += nxt
	}
}

func q2(f *os.File) {
	code := parser(f)
	p0_out := &[]int{}
	p1_out := &[]int{}

	steps := 100
	p0 := NewCode(&code, 0, p1_out, p0_out)
	p1 := NewCode(&code, 1, p0_out, p1_out)

	for {
		r0, r0_send := p0(steps)
		r1, r1_send := p1(steps)

		if r0 && r1 && len(*p0_out) == 0 && len(*p1_out) == 0 {
			fmt.Println("p0 send ", r0_send, "p1 send ", r1_send)
			break
		}
	}
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
