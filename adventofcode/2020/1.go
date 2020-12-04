package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func q1(f *os.File) {
	expenses := make(map[int]int)
	input := bufio.NewScanner(f)
	for input.Scan() {
		e, _ := strconv.Atoi(input.Text())
		if expenses[2020-e] == 1 {
			fmt.Printf("%v\n", e*(2020-e))
			break
		}
		expenses[e] = 1
	}
}

func q2(f *os.File) {
	expenses := make([]int, 0)
	input := bufio.NewScanner(f)
	for input.Scan() {
		e, _ := strconv.Atoi(input.Text())
		expenses = append(expenses, e)
	}

	for i := 0; i < len(expenses); i ++ {
		for j := i + 1; j < len(expenses); j ++ {
			for k := j + 1; k < len(expenses); k ++ {
				if 2020 == expenses[i] + expenses[j] + expenses[k] {
					fmt.Printf("%v\n", expenses[i] * expenses[j] * expenses[k])
					os.Exit(0)
				}
			}
		}
	}
}

func main() {
	f, _ := os.Open(os.Args[1:][0])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
