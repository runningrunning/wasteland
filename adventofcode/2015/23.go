package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parse(f *os.File) (all [][]string) {
	f.Seek(0, 0)
	input := bufio.NewScanner(f)
	for input.Scan() {
		ws := strings.Split(strings.TrimSpace(input.Text()), " ")
		// remove the ','
		if ws[1][len(ws[1])-1] == ',' {
			ws[1] = ws[1][:len(ws[1])-1]
		}
		all = append(all, ws)
	}
	return
}

func q1(f *os.File) {
	all := parse(f)
	registers := make(map[string]int)
	registers["a"] = 1
	i := 0
	for i < len(all) {
		nxt := 1

		switch all[i][0] {
		case "hlf":
			registers[all[i][1]] /= 2
		case "tpl":
			registers[all[i][1]] *= 3
		case "inc":
			registers[all[i][1]] += 1
		case "jmp":
			nxt, _ = strconv.Atoi(all[i][1])
		case "jie":
			if registers[all[i][1]]&1 == 0 {
				nxt, _ = strconv.Atoi(all[i][2])
			}
		case "jio":
			if registers[all[i][1]] == 1 {
				nxt, _ = strconv.Atoi(all[i][2])
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
