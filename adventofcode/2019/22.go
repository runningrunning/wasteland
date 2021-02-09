// How to Q2?
// Go: Use big int
// Convert to bigger number ?
// Overflow :(
// Solve through pike (big int)
// Modulo inverse
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var incache map[int]map[int]int

func apply_notused(steps [][2]int, reverse bool, l, x int) int {
	for i := 0; i < len(steps); i++ {
		op, oc := 0, 0
		if reverse {
			op = steps[len(steps)-1-i][0]
			oc = steps[len(steps)-1-i][1]
		} else {
			op = steps[i][0]
			oc = steps[i][1]
		}

		switch op {

		case 0:
			x = l - 1 - x
		case 1:
			if oc < 0 {
				oc += l
			}

			if reverse {
				oc = l - oc
			}
			if x < oc {
				x += l - oc
			} else {
				x -= oc
			}
		case 2:
			if reverse {
				if _, ok := incache[oc]; !ok {
					incache[oc] = make(map[int]int)
				}

				for j := 0; j < l; j++ {
					if (j*oc)%l == x {
						fmt.Println(x, j)
						incache[oc][x] = j
						x = j
						break
					}
				}
			} else {
				x = (x * oc) % l
			}
		}
	}
	return x
}

func apply(steps [][2]int, l, x int) int {
	for i := 0; i < len(steps); i++ {
		op, oc := steps[i][0], steps[i][1]
		switch op {
		case 0:
			x = l - 1 - x
		case 1:
			if oc < 0 {
				oc += l
			}

			if x < oc {
				x += l - oc
			} else {
				x -= oc
			}
		case 2:
			x = (x * oc) % l
		}
	}
	return x
}

func parser(f *os.File) [][2]int {
	var steps [][2]int

	input := bufio.NewScanner(f)

	for input.Scan() {
		if input.Text() == "deal into new stack" {
			steps = append(steps, [2]int{0, 0})
		} else if strings.HasPrefix(input.Text(), "cut") {
			var number int
			fmt.Sscanf(input.Text(), "cut %d", &number)
			steps = append(steps, [2]int{1, number})
		} else {
			var number int
			fmt.Sscanf(input.Text(), "deal with increment %d", &number)
			steps = append(steps, [2]int{2, number})
		}
	}
	return steps
}

func q1(steps [][2]int, l, x int) int {
	return apply(steps, l, x)
}

func q2(steps [][2]int, l, x int) int {
	fmap := make(map[int]int)
	cache := make(map[int]int)
	for i := 0; i < l; i++ {
		t := apply(steps, l, i)
		if t == x {
			fmt.Println(t, x)
		}
		fmap[t] = i

		t = apply(steps, l-i, i)
		if t == x {
			fmt.Println(t, x)
		}
		fmap[t] = l - i
	}

	fmt.Println("fmap is done")

	for i := 0; i < 101741582076661; i++ {
		if last, ok := cache[x]; ok {
			fmt.Println("Got cache before, try to skip.", last, i, x)
			dis := last - i
			i = 101741582076661 - ((101741582076661 - i) % dis)
		} else {
			cache[x] = i
			x = fmap[x]
		}
	}
	return x
}

func q2_1(steps [][2]int, l, x int) int {
	x = 0
	fmap := make(map[int]int)
	for i := 0; i < l; i++ {
		t := apply(steps, l, x)
		if _, ok := fmap[t]; ok {
			fmt.Println("again. break ", x, t)
			break
		}
		fmap[t] = x
		x = t
	}
	return x
}

func s1(steps [][2]int, l int) (st, step int) {
	st = 0
	step = 1

	for _, s := range steps {
		op, oc := s[0], s[1]
		switch op {
		case 0:
			step = -step
			st += step
		case 1:
			// if oc < 0 {
			// 	oc += l
			// }
			fmt.Println(oc, step, oc*step, st)
			st += oc * step
			fmt.Println("after", st)
		case 2:
			fmt.Println("2", step, oc, l, offset(oc, l))
			step *= offset(oc, l)
			fmt.Println("2 after", step)
		}
		st %= l
		step %= l
	}
	return st%l, step%l
}

func q2_2(steps [][2]int, l, x int) int {
	st, sp := s1(steps, l)
	fmt.Println(st, sp)

	for i := 0; i < 500; i ++ {
		fmt.Printf("%d:%d: ", i, ((st%l) +  l)%l)
		st += sp
	}

	fmt.Println()
	return 0
}

func offset(align, l int) int {
	x := l
	for {
		if ((x + 1) % align) == 0 {
			break
		}
		x += l
	}
	return (x + 1) / align
}

func test(steps [][2]int) {
	// for i := 0; i < 10; i ++ {
	// 	fmt.Println(q1(steps, 10, i))
	// }

	// q2_2(steps, 10, 0)
	// q2_2(steps, 119315717514047, 0)
	fmt.Println(q1(steps, 119315717514047, 0))
	fmt.Println(q1(steps, 119315717514047, 1))
	fmt.Println(q1(steps,119315717514047, 47995993305898))
	// fmt.Println(q1(steps, 119315717514047, 2))
	// fmt.Println(q1(steps, 119315717514047, 3))
	// fmt.Println(q1(steps, 119315717514047, 4))
	// fmt.Println(q1(steps, 119315717514047, 5))
	// fmt.Println(q1(steps, 119315717514047, 6))
	// fmt.Println(q1(steps, 10007, 2019))
	// for i := 2; i < 10; i ++ {
	// 	fmt.Println(i, offset(i, 119315717514047))
	// }
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	steps := parser(f)
	test(steps)
	// fmt.Println(q1(steps, 10007, 2019))
}
