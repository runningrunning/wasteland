// becareful
// use list ???

package main

import (
	"fmt"
)

// wrong answer, as move l-3 is harder

// func q1(in []int, turns int) {
// 	c := 0
// 	l := len(in)
// 	temp := make([]int, 3)

// 	for i := 0; i < turns; i++ {
// 		for j := 0; j < 3; j++ {
// 			temp[j] = in[(c+1+j)%l]
// 		}

// 		// keep c in the loop
// 		min := in[c]
// 		max := in[c]

// 		for j := 0; j < l-1-3; j++ {
// 			t := in[(c+1+3+j)%l]
// 			in[(c+1+j)%l] = t

// 			if min > t {
// 				min = t
// 			}

// 			if max < t {
// 				max = t
// 			}
// 		}

// 		fmt.Println(temp)
// 		fmt.Println(in)
// 		n := in[c] - 1

// 		for {
// 			if n != temp[0] && n != temp[1] && n != temp[2] {
// 				if n < min {
// 					n = max
// 				}

// 				found := false

// 				for j := 0; j < l - 3; j ++ {
// 					if in[(c+j)%l] == n {
// 						x := (c + j) % l
// 						fmt.Println("found", n, x)
// 						for k := 0; k < l - 1 - 3; k ++ {
// 							in[(x - 1 - k + l) % l] = in[(x - 1 - k + l - 3)%(l-3)]
// 						}
// 						// fmt.Println(in)
// 						// fmt.Println("==")

// 						for k := 0; k < 3; k ++ {
// 							in[(x+k+1)%l] = temp[k]
// 						}
// 						// fmt.Println(in)
// 						// fmt.Println("==")
// 						found = true
// 						break
// 					}
// 				}

// 				if found {
// 					break
// 				}
// 			}
// 			n -= 1
// 		}
// 		c = (c + 1)%l
// 		fmt.Println(in)
// 	}
// }

// tooooo slow version
func q1(in []int, turns int) {
	l := len(in)

	nxt := make([]int, l)

	for i := 0; i < turns; i++ {
		fmt.Println(i)
		min := in[0]
		max := in[0]

		for j := 0; j < l-3; j++ {
			nxt[j] = in[(j+1+3)%l]

			if min > nxt[j] {
				min = nxt[j]
			}

			if max < nxt[j] {
				max = nxt[j]
			}
		}

		// fmt.Println(" ", nxt)

		n := in[0] - 1

		for {
			if n != in[1] && n != in[2] && n != in[3] {
				if n < min {
					n = max
				}

				found := false

				for j := 0; j < l-3; j++ {
					if nxt[j] == n {
						found = true
						// becareful here, it's -3
						for k := l - 1; k > j+3; k-- {
							nxt[k] = nxt[k-3]
						}
						// fmt.Println(" ", nxt)
						nxt[j+1] = in[1]
						nxt[j+2] = in[2]
						nxt[j+3] = in[3]
						// fmt.Println(" ", nxt)
						break
					}
				}

				if found {
					break
				}
			}
			n -= 1
		}

		nxt, in = in, nxt
		// fmt.Println(in)
	}

	for i := range in {
		if in[i] == 1 {
			// for j := 0; j < l - 1; j ++ {
			// 	fmt.Print(in[(i+1+j)%l])
			// }
			// fmt.Println("")
			// break

			fmt.Println(in[(i+1)%l], in[(i+2)%l], in[(i+1)%l]*in[(i+2)%l])
		}
	}
}

func increasing(in []int) int {
	for i := 4; i < len(in); i+=4 {
		if in[i] - in[i-1] == 1 {
			continue
		}
		return i - 4
	}
	return 0
}

func q2(in []int, turns int) {
	l := len(in)
	nxt := make([]int, l)

	for i := 0; i < turns; {
		fmt.Println(i, in)
		maxl := increasing(in)
		if maxl > 8 {
			t := maxl / 4

			if t > (turns - i) {
				t = turns - i
			}

			insert := 0

			for j := t * 4; j < l; j++ {
				if in[j] == in[0]-1 {
					insert = j
					break
				}
			}

			for j := t * 4; j <= insert; j++ {
				nxt[j-4*t] = in[j]
			}


			// for j := 0; j < t; j++ {
			// 	nxt[j] = in[j*4]
			// }

			st := insert - 4 * t
			for j := 0; j < t; j++ {
				for k := 0; k < 3; k++ {
					st = st + 1
					nxt[st] = in[j*4+1+k]
				}
			}

			for j := insert + 1; j < l; j++ {
				nxt[j-t] = in[j]
			}

			for j := 0; j < t; j ++ {
				nxt[l - t + j] = in[j*4]
			}

			fmt.Println(t)
			i += t
		} else {
			min := in[0]
			max := in[0]

			for j := 0; j < l-3; j++ {
				nxt[j] = in[(j+1+3)%l]

				if min > nxt[j] {
					min = nxt[j]
				}

				if max < nxt[j] {
					max = nxt[j]
				}
			}

			// fmt.Println(" ", nxt)

			n := in[0] - 1

			for {
				if n != in[1] && n != in[2] && n != in[3] {
					if n < min {
						n = max
					}

					found := false

					for j := 0; j < l-3; j++ {
						if nxt[j] == n {
							found = true
							// becareful here, it's -3
							for k := l - 1; k > j+3; k-- {
								nxt[k] = nxt[k-3]
							}
							// fmt.Println(" ", nxt)
							nxt[j+1] = in[1]
							nxt[j+2] = in[2]
							nxt[j+3] = in[3]
							// fmt.Println(" ", nxt)
							break
						}
					}

					if found {
						break
					}
				}
				n -= 1
			}
			i++
		}
		nxt, in = in, nxt
	}
	fmt.Println(in)
}

func main() {
	input := []int{3, 8, 9, 1, 2, 5, 4, 6, 7}
	// input := []int{1,9,8,7,5,3,4,6,2}
	// q1(input, 100)
	// m, n := 1000000, 10000000
	m, n := 100, 50

	in2 := make([]int, m)
	for i := range in2 {
		in2[i] = i + 1
	}
	for i, v := range input {
		in2[i] = v
	}
	// q1(in2, n)
	q2(in2, n)
}
