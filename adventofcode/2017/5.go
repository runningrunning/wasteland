package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func q1(f *os.File) {
	var ins []int
	input := bufio.NewScanner(f)
	for input.Scan() {
		x, _ := strconv.Atoi(input.Text())
		ins = append(ins, x)
	}
	pc := 0
	steps := 0
	for pc < len(ins) {
		nxt := pc + ins[pc]
		ins[pc] += 1
		steps += 1
		pc = nxt
	}
	fmt.Println(steps)
}


func q2(f *os.File) {
	var ins []int
	input := bufio.NewScanner(f)
	for input.Scan() {
		x, _ := strconv.Atoi(input.Text())
		ins = append(ins, x)
	}
	pc := 0
	steps := 0
	for pc < len(ins) {
		nxt := pc + ins[pc]
		if ins[pc] >= 3 {
			ins[pc] -= 1
		} else {
			ins[pc] += 1
		}
		steps += 1
		pc = nxt
	}
	fmt.Println(steps)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
