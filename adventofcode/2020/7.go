package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func canHold(all map[string]map[string]int, cur, bag string) int {
	num := 0

	if cur == "" {
		for n, _ := range all {
			if canHold(all, n, bag) != 0 {
				num++
			}
		}
		return num
	} else {

		if cur == bag {
			return 1
		}

		for n, _ := range all[cur] {
			num += canHold(all, n, bag)
			if num != 0 {
				return 1
			}
		}
		return 0
	}
	return 0
}

// sscanf will stop in ' '
func q1(f *os.File) {
	rules := map[string]map[string]int{}
	input := bufio.NewScanner(f)
	for input.Scan() {
		line := input.Text()
		if len(line) == 0 {
			break
		}

		tokens := strings.Split(line, " ")
		var name string
		for i, t := range tokens {
			if t == "bags" {
				name = strings.Join(tokens[:i], " ")
				tokens = tokens[i+2:]
				break
			}
		}

		if tokens[0] == "no" {
			rules[name] = nil
			continue
		}

		si := -1
		num := -1
		contains := map[string]int{}
		for i, t := range tokens {
			if t == "bags," || t == "bags." || t == "bag," || t == "bag." {
				contains[strings.Join(tokens[si:i], " ")] = num
				si = -1
				num = -1
			} else if num == -1 {
				num, _ = strconv.Atoi(t)
			} else if si == -1 {
				si = i
			}
		}
		rules[name] = contains
	}

	// minus itself -1
	fmt.Println(canHold(rules, "", "shiny gold") - 1)
}

func needHold(all map[string]map[string]int, cur string) int {
	num := 1

	if all[cur] == nil {
		return 1
	}

	for n, c := range all[cur] {
		num += c * needHold(all, n)
	}

	return num
}

func q2(f *os.File) {
	rules := map[string]map[string]int{}
	input := bufio.NewScanner(f)
	for input.Scan() {
		line := input.Text()
		if len(line) == 0 {
			break
		}

		tokens := strings.Split(line, " ")
		var name string
		for i, t := range tokens {
			if t == "bags" {
				name = strings.Join(tokens[:i], " ")
				tokens = tokens[i+2:]
				break
			}
		}

		if tokens[0] == "no" {
			rules[name] = nil
			continue
		}

		si := -1
		num := -1
		contains := map[string]int{}
		for i, t := range tokens {
			if t == "bags," || t == "bags." || t == "bag," || t == "bag." {
				contains[strings.Join(tokens[si:i], " ")] = num
				si = -1
				num = -1
			} else if num == -1 {
				num, _ = strconv.Atoi(t)
			} else if si == -1 {
				si = i
			}
		}
		rules[name] = contains
	}

	// minus itself -1
	fmt.Println(needHold(rules, "shiny gold") - 1)
}

func main() {
	f, _ := os.Open(os.Args[1])
	q1(f)
	f.Seek(0, 0)
	q2(f)
	f.Close()
}
