package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func q1(f *os.File) {
	input := bufio.NewScanner(f)
	registers := make(map[string]int64)
	registers["c"] = int64(1)

	var ins [][]string

	for input.Scan() {
		ins = append(ins, strings.Split(input.Text(), " "))
	}

	valueof := func(x string) int64 {
		if len(x) == 1 && x[0] >= 'a' && x[0] <= 'd' {
			return registers[x]
		}
		n, _ := strconv.Atoi(x)
		return int64(n)
	}

	i := 0

	for i < len(ins) {
		ws := ins[i]
		nxt := 1
		switch ws[0] {
		case "cpy":
			registers[ws[2]] = valueof(ws[1])
		case "inc":
			registers[ws[1]]++
		case "dec":
			registers[ws[1]]--
		case "jnz":
			if valueof(ws[1]) != 0 {
				nxt = int(valueof(ws[2]))
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
