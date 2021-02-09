package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Token struct {
	Value    int
	Operator string
}

func print(tokens []Token) string {
	s := ""
	for _, t := range tokens {
		if t.Operator == "" {
			s += fmt.Sprintf("%d,", t.Value)
		} else {
			s += t.Operator + ","
		}
	}
	return s
}

func tokenize(s string) []Token {
	var tokens []Token

	for i := 0; i < len(s); {
		if s[i] == ' ' {
			i++
			continue
		}

		w := 0

		if s[i] == '+' || s[i] == '*' || s[i] == '(' || s[i] == ')' {
			w = 1
			tokens = append(tokens, Token{0, s[i : i+w]})
		} else {
			for {
				if i+w == len(s) || s[i+w] < '0' || s[i+w] > '9' {
					break
				}
				w++
			}
			v, _ := strconv.Atoi(s[i : i+w])
			tokens = append(tokens, Token{v, ""})
		}
		i += w
	}
	return tokens
}

func eone(t1, op, t2 Token) (Token, bool) {
	if t1.Operator == "" && op.Operator != "(" && t2.Operator == "" {
		switch op.Operator {
		case "+":
			t1.Value += t2.Value
		case "*":
			t1.Value *= t2.Value
		}
		return t1, true
	}
	return Token{}, false
}

func eval1(tokens []Token) int {
	stack := make([]Token, len(tokens)+1)
	top := -1
	for _, t := range tokens {
		if t.Operator == ")" {
			// top - 1 must be "("
			if stack[top-1].Operator != "(" {
				fmt.Println("Error here, should be (, but got " + stack[top-1].Operator)
			}
			stack[top-1] = stack[top]
			top--
		} else {
			top++
			stack[top] = t
		}

		// eval current stack
		if top >= 2 {
			if temp, ok := eone(stack[top-2], stack[top-1], stack[top]); ok {
				stack[top-2] = temp
				top -= 2
			}
		}
	}
	return stack[0].Value
}

func eval2(tokens []Token) int {
	stack := make([]Token, len(tokens)+1)
	top := -1

	for _, t := range tokens {
		if t.Operator == ")" {
			for {
				if stack[top-1].Operator == "(" {
					break
				}
				// contain * op
				if temp, ok := eone(stack[top-2], stack[top-1], stack[top]); ok {
					stack[top-2] = temp
					top -= 2
				} else {
					fmt.Println("Error here, should be correct expression " + print(stack[top-2:top+1]))
				}
			}
			stack[top-1] = stack[top]
			top--
		} else {
			top++
			stack[top] = t
		}

		// eval only + here
		if top >= 2 {
			if stack[top-1].Operator == "+" {
				if temp, ok := eone(stack[top-2], stack[top-1], stack[top]); ok {
					stack[top-2] = temp
					top -= 2
				}
			}
		}
	}

	for top != 0 {
		// contain * op only
		if temp, ok := eone(stack[top-2], stack[top-1], stack[top]); ok {
			stack[top-2] = temp
			top -= 2
		} else {
			fmt.Println("Error here, should be correct expression " + print(stack[top-2:top+1]))
		}
	}
	return stack[0].Value
}

func q1(f *os.File) {
	sum := 0
	input := bufio.NewScanner(f)
	for input.Scan() {
		tokens := tokenize(input.Text())
		sum += eval1(tokens)
	}
	fmt.Println(sum)
}

func q2(f *os.File) {
	sum := 0
	input := bufio.NewScanner(f)
	for input.Scan() {
		tokens := tokenize(input.Text())
		temp := eval2(tokens)
		// fmt.Println(input.Text(), "=", temp)
		sum += temp
	}
	fmt.Println(sum)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
