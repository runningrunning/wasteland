package main

import "fmt"

func eqal(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}

	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}

	return true
}
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

func eliminateDup2(s []string) []string {
	if len(s) <= 1 {
		return s
	}

	t := s[:1]
	for _, x := range s[1:] {
		if x != t[len(t)-1] {
			t = append(t, x)
		}
	}
	return t
}

func main() {
	s := []string{"1", "1", "0", "0", "1", "1", "2", "3", "我", "我", "的", "的", "的", "的", "的", "2", "3", "3", "4", "5"}
	fmt.Println(s)
	s = eliminateDup2(s)
	fmt.Println(s)
}
