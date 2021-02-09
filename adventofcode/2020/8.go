package main

// Be more carefule about copy in go
// r_encount = encount will not copy the value, just pass the reference
// use below instead
//
// encount = make([]bool, len(code))
// copy(encount, r_encount)
// AND DON'T USE := as it will not affect the outer variable
// Or
// copy(destSlice, srcSlice []T) int !!!!!!!!!!!!!!!!!

import (
	"bufio"
	"fmt"
	"os"
)

type ins struct {
	op string
	on int
}

func read(f *os.File) []ins {
	instruction := []ins{}
	input := bufio.NewScanner(f)
	for input.Scan() {
		var (
			c string
			n int
		)
		if len(input.Text()) == 0 {
			break
		}
		fmt.Sscanf(input.Text(), "%s %d", &c, &n)
		instruction = append(instruction, ins{c, n})
	}
	return instruction
}

func run(code []ins) int {
	ac := 0
	pc := 0
	encount := make([]bool, len(code))
	for {
		if encount[pc] {
			return ac
		}
		cur := &code[pc]
		encount[pc] = true
		if cur.op == "nop" {
			pc++
		} else if cur.op == "acc" {
			pc++
			ac += cur.on
		} else if cur.op == "jmp" {
			pc += cur.on
		}
	}
	return 0
}

func correct(code []ins) int {
	ac := 0
	pc := 0
	r_ac := 0
	r_pc := 0
	modify := false
	changed := make([]bool, len(code))

	encount := make([]bool, len(code))
	r_encount := make([]bool, len(code))

	for {
		if pc == len(code) {
			return ac
		}

		if pc > len(code) || encount[pc] {
			// restore back
			ac = r_ac
			pc = r_pc
			// copy r_encount => encount
			copy(encount, r_encount)
			modify = false
		}

		cur := &code[pc]
		encount[pc] = true

		if cur.op == "nop" {
			if changed[pc] || modify {
				pc++
			} else {
				changed[pc] = true
				r_ac = ac
				r_pc = pc
				// copy encount => r_encount
				copy(r_encount, encount)
				modify = true
				// try jump
				pc += cur.on
			}
		} else if cur.op == "acc" {
			pc++
			ac += cur.on
		} else if cur.op == "jmp" {
			if changed[pc] || modify {
				pc += cur.on
			} else {
				changed[pc] = true
				r_ac = ac
				r_pc = pc
				// copy encount => r_encount
				copy(r_encount, encount)
				modify = true
				pc++
			}
		}
	}
	return 0
}

func q1(f *os.File) {
	all := read(f)
	fmt.Println(run(all))
}

func q2(f *os.File) {
	all := read(f)
	fmt.Println(correct(all))
}

func main() {
	f, _ := os.Open(os.Args[1])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
