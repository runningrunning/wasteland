package main

import "fmt"

func eliminateDup(s []string) []string {
	if len(s) <= 1 {
		return s
	}

	top := 0

	for i := 1; i < len(s); i++ {
		if s[top] != s[i] {
			s[top+1] = s[i]
			top++
		}
	}
	return s[:top+1]
}

func main() {
	s := []string{"1", "1", "0", "0", "1", "1", "2", "3", "我", "我", "的", "的", "的", "的", "的", "2", "3", "3", "4", "5"}
	fmt.Println(s)
	s = eliminateDup(s)
	fmt.Println(s)
}
