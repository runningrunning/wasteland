// keep it simple.
package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func q1(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	decoded := ""

	var marked = false
	mark_l, mark_t := 0, 0
	marked_s := ""

	for i := 0; i < len(input); i++ {
		if marked {
			marked_s += string(input[i])
			if len(marked_s) == mark_l {
				for j := 0; j < mark_t; j++ {
					decoded += marked_s
				}
				marked_s = ""
				marked = false
				mark_l, mark_t = 0, 0
			}
		} else {
			if input[i] == '(' {
				end := strings.IndexByte(input[i:], ')')
				if end == -1 {
					fmt.Errorf("Something wrong in inputs")
					os.Exit(1)
				}
				m := strings.Split(input[i+1:i+end], "x")
				n, _ := strconv.Atoi(m[0])
				mark_l = n
				n, _ = strconv.Atoi(m[1])
				mark_t = n
				marked = true
				marked_s = ""
				i += end
			} else {
				decoded += string(input[i])
			}
		}
	}
	fmt.Println(decoded, len(decoded))
}

/* // Keep it simple
type Mark struct {
	index, length, times int
	marks                []*Mark
}

func simplify(r *Mark) {
}

func output(r *Mark) {
	fmt.Println(r.index, r.length, r.times)
	if r.marks != nil {
		fmt.Println("Contain === START")
		for _, m := range r.marks {
			output(m)
		}
		fmt.Println("Contain === END")
	}
}

func q2(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	root := Mark{0, len(input), 1, nil}
	var stack []*Mark
	stack = append(stack, &root)

	for i := 0; i < len(input); i++ {
		if input[i] == '(' {
			end := strings.IndexByte(input[i:], ')')
			if end == -1 {
				fmt.Errorf("Something wrong in inputs.")
				os.Exit(1)
			}
			m := strings.Split(input[i+1:i+end], "x")
			mark_l, _ := strconv.Atoi(m[0])
			mark_t, _ := strconv.Atoi(m[1])
			mark := Mark{i + end + 1, mark_l, mark_t, nil}
			for j := len(stack) - 1; j >= 0; j-- {
				if mark.index+mark.length <= stack[j].index+stack[j].length {
					stack[j].marks = append(stack[j].marks, &mark)
					stack = append(stack, &mark)
					break
				}
			}
			i += end
		}	output(&root)
}
*/

type Mark struct {
	end, length, times int
}

func q2(f *os.File) int {
	raw, _ := ioutil.ReadAll(f)
	input := strings.TrimSpace(string(raw))

	root := Mark{len(input) - 1, 0, 1}
	var stack []Mark
	stack = append(stack, root)

	for i := 0; i < len(input); i++ {
		if input[i] == '(' {
			end := strings.IndexByte(input[i:], ')')
			if end == -1 {
				fmt.Errorf("Something went wrong.\n")
				os.Exit(1)
			}
			m := strings.Split(input[i+1:i+end], "x")
			mark_l, _ := strconv.Atoi(m[0])
			mark_t, _ := strconv.Atoi(m[1])
			stack = append(stack, Mark{i + end + mark_l, 0, mark_t})
			i += end
		} else {
			stack[len(stack)-1].length++
			for (i == stack[len(stack)-1].end) && len(stack) != 1 {
				last := stack[len(stack)-1].length * stack[len(stack)-1].times
				stack = stack[:len(stack)-1]
				stack[len(stack)-1].length += last
			}
		}
	}
	return stack[0].length
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	fmt.Println(q2(f))
}
