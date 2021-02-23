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

func run(ins [][]string, a int) bool {
	registers := make(map[string]int64)
	registers["a"] = int64(a)

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
	times := 0
	pre := int64(1)

	for i < len(ins) {
		ws := ins[i]
		nxt := 1
		switch ws[0] {
		case "cpy":
			reg(ws[2], valueof(ws[1]))
		case "inc":
			reg(ws[1], registers[ws[1]]+1)
		case "dec":
			reg(ws[1], registers[ws[1]]-1)
		case "jnz":
			if valueof(ws[1]) != 0 {
				nxt = int(valueof(ws[2]))
			}
		case "out":
			x := valueof(ws[1])
			if (x != 0 && x != 1) || pre == x {
				return false
			}
			pre = x
			times++

			if times > 10240 && times > 5*a {
				return true
			}

		case "tgl":
			x := int(valueof(ws[1]))
			if x == 0 {
				ins[i] = []string{"inc", "a"}
			} else if (i+x < len(ins)) && (i+x >= 0) {
				switch ins[i+x][0] {
				case "inc":
					ins[i+x][0] = "dec"
				case "dec":
					ins[i+x][0] = "inc"
				case "tgl":
					ins[i+x][0] = "inc"
				case "jnz":
					ins[i+x][0] = "cpy"
				case "cpy":
					ins[i+x][0] = "jnz"

				}
			}
		}
		i += nxt
	}
	return false
}
func q1(f *os.File) {
	input := bufio.NewScanner(f)
	var ins [][]string
	for input.Scan() {
		ws := strings.Split(input.Text(), " ")
		ins = append(ins, ws)
	}

	i := 1

	for !run(ins, i) {
		i++
	}

	fmt.Println(i)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
