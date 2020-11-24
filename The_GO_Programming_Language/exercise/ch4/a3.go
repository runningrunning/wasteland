package main

import "fmt"

func reverseInt(a *[10]int) *[10]int {
	for i, j := 0, len(a) - 1; j > i; i, j = i + 1, j - 1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func main() {
	a := [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
	fmt.Println(a)
	reverseInt(&a)
	fmt.Println(a)
}
