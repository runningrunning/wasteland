// TODO ?
// better solution ?
package main

import (
	"fmt"
	"reflect"
)

func q1(input []int, num int) {
	last := make(map[int]int)
	all := input

	for i := 0; i < len(input)-1; i++ {
		last[input[i]] = i + 1
	}

	for i := len(all); i < num; i++ {
		x := all[len(all)-1]
		if last[x] != 0 {
			all = append(all, i-last[x])
		} else {
			all = append(all, 0)
		}
		last[x] = i
	}
	fmt.Println(all[len(all)-1])
}


// find the repeat?
func q2(input []int, num int) {
	last := make(map[int]int)
	all := input

	for i := 0; i < len(input)-1; i++ {
		last[input[i]] = i + 1
	}

	for i := len(all); i < num; i++ {
		x := all[len(all) - 1]
		if last[x] != 0 {
			all = append(all, i - last[x])
			if all[i] == all[last[x]] && (i - last[x] <= last[x]){
				// Repeat sequence 
				if reflect.DeepEqual(all[last[x]:i + 1], all[last[x] + last[x] - i :last[x] + 1]) {
					fmt.Println("Same")
					break
				}
			}
		} else {
			all = append(all, 0)
		}
		last[x] = i
	}
}

func main() {
	// q1([]int{0, 3, 6}, 2020)
	// q1([]int{1, 3, 2}, 2020)
	// q1([]int{2, 1, 3}, 2020)
	// q1([]int{1, 2, 3}, 2020)
	// q1([]int{2, 3, 1}, 2020)
	// q1([]int{3, 2, 1}, 2020)
	// Doesn't work
	q1([]int{12, 20, 0, 6, 1, 17, 7}, 30000000)
	q2([]int{12, 20, 0, 6, 1, 17, 7}, 9000000000)
}
