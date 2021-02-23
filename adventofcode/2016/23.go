package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func output(in [][]string) {
	for i, ins := range in {
		fmt.Println(i, ":", ins)
	}
	fmt.Println()
}

func q1(f *os.File) {
	input := bufio.NewScanner(f)
	registers := make(map[string]int64)
	registers["a"] = 12
	var ins [][]string
	var ntgl = 0

	for input.Scan() {
		ws := strings.Split(input.Text(), " ")
		if ws[0] == "tgl" {
			ntgl ++
		}
		ins = append(ins, ws)
	}

	valueof := func(x string) int64 {
		if len(x) == 1 && x[0] >= 'a' && x[0] <= 'd' {
			return registers[x]
		}
		n, _ := strconv.Atoi(x)
		return int64(n)
	}

	reg := func(k string, v int64) {
		if len(k) == 1 && k[0] >= 'a' && k[0] <= 'd' {
			registers[k] = v
		}
	}

	i := 0
	for i < len(ins) {
		ws := ins[i]
		nxt := 1
		switch ws[0] {
		case "cpy":
			reg(ws[2], valueof(ws[1]))
		case "inc":
			reg(ws[1], registers[ws[1]] + 1)
		case "dec":
   			reg(ws[1], registers[ws[1]] - 1)
		case "jnz":
			if valueof(ws[1]) != 0 {
				nxt = int(valueof(ws[2]))
			}
		case "tgl":
			fmt.Println(i, registers)
			x := int(valueof(ws[1]))
			if x == 0 {
				ntgl --
				ins[i] = []string{"inc", "a"}
			} else if (i+x < len(ins)) && (i+x >= 0) {
				switch ins[i+x][0] {
				case "inc":
					ins[i+x][0] = "dec"
				case "dec":
					ins[i+x][0] = "inc"
				case "tgl":
					ntgl --
					ins[i+x][0] = "inc"
				case "jnz":
					ins[i+x][0] = "cpy"
				case "cpy":
					ins[i+x][0] = "jnz"

				}
			}

			if ntgl == 0 {
				fmt.Println("TGL is done", i)
				fmt.Println(registers)
				output(ins)
			}
		}
		i += nxt
	}
	fmt.Println(registers)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}

// cpy a b   b = a = 12
// dec b     b -- = 11
// cpy a d   d = a = 12                            d = a = 132
// cpy 0 a   a = 0                                 a = 0
// cpy b c   c = b = 11                            c = b = 10
// inc a     a + 1 = 1                             a += 1
// dec c     c -- = 10                             c -- = 9
// jnz c -2  a = 11, c = 0                         a = 10, c = 0
// dec d     d - 1 = 11                            d - 1 = 131
// jnz d -5  a = 132, c = 0, d = 0, b = 11         a = 10 * 132, c = 0, d = 0, b = 10
// dec b     a = 132, c = 0, d = 0, b = 10         a = 10 * 132, c = 0, d = 0, b = 9
// cpy b c   c = b = 10                            c = b = 9
// cpy c d   d = c = 10                            d = c = 9
// dec d     d = 9                                 d = 8
// inc c     c = 11                                c = 10
// jnz d -2  c = 20, d = 0                         c = 18, d = 0
// tgl c     a = 132, b = 10, c = 20, d = 0        a = 10 * 132, b = 9, c = 18, d = 0   a = 9 * 10 * 132, b = 9, c = 16

// cpy -16 c     c = -16 , b = 2, d = 0, a = 479001600
// cpy 1 c       c = 1
// cpy 78 c      c = 78

// cpy 70 d      d = 70
// inc a         a += 1
// dec d
// jnz d -2      479001670, d = 0,
// dec c         c = 77
// jnz c -5

// 78 * 70 + 479001670;



// a = 8 * 9 * 10 * 11 * 12, b = 8, c = 14
// a = 7 * 8 * 9 * 10 * 11 * 12, b = 7, c = 12
// a = 6 * 7 * 8 * 9 * 10 * 11 * 12, b = 6, c = 10
// a = 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12, b = 5, c = 8
// a = 4 * 5 8 * 9 * 10 * 11 * 12, b = 4, c = 6
// a = 3 * 8 * 9 * 10 * 11 * 12, b = 3, c = 4
// a = 2 * 8 * 9 * 10 * 11 * 12, b = 2, c = 2
