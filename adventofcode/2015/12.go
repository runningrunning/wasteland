// json parser
// implement a no recursive version
package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

type JsType int

const (
	Number JsType = iota
	String
	Object
	Array
)

type JS struct {
	t JsType
	n int
	s string
	a []*JS
	o map[string]*JS
}

func error(w, s string, e JsType) {
	fmt.Printf("Something wrong here. Need %s Got %s for %d \n", w, s, e)
	os.Exit(1)
}

func sum(r *JS, e string) (s int) {
	if contain(r, e) {
		return 0
	}

	switch r.t {
	case Number:
		return r.n
	case String:
		return 0
	case Array:
		for _, n := range r.a {
			s += sum(n, e)
		}
	case Object:
		for _, n := range r.o {
			s += sum(n, e)
		}
	}
	return
}

func contain(r *JS, s string) bool {
	if s == "" {
		return false
	}

	switch r.t {
	case Number:
		return false
	case String:
		return r.s == s
	case Array:
		return false
	case Object:
		for k, v := range r.o {
			if k == s {
				return true
			}
			// Only its direct children, not children of children !
			if v.t == String && v.s == s {
				return true
			}

			// all of its children
			// if contain(v, s) {
			// 	fmt.Println(v, "still contain")
			// }
		}
	}
	return false
}

func parser(s string) (cur *JS, left string) {
	cur = new(JS)
	if s[0] == '[' {
		cur.t = Array
		var v *JS
		l := s[1:]
		for {
			v, l = parser(l)
			cur.a = append(cur.a, v)

			if l[0] == ']' {
				left = l[1:]
				break
			} else if l[0] != ',' {
				error(",", l[:1], Array)
			}
			l = l[1:]
		}
	} else if s[0] == '{' {
		cur.t = Object
		var k, v *JS
		l := s[1:]
		for {
			k, l = parser(l)
			if l[0] != ':' {
				error(":", l[:1], Object)
			}
			v, l = parser(l[1:])

			if cur.o == nil {
				cur.o = make(map[string]*JS)
			}

			if k.t != String {
				error("String", "non string", k.t)
			}

			cur.o[k.s] = v

			if l[0] == '}' {
				left = l[1:]
				break
			} else if l[0] != ',' {
				error(",", l[:1], Object)
			}
			l = l[1:]
		}
	} else if s[0] == '"' {
		i := 1
		for s[i] != '"' {
			i++
		}
		cur.t = String
		cur.s = s[1:i]
		// skip the last "
		left = s[i+1:]
	} else {
		if s[0] == '-' || (s[0] >= '0' && s[0] <= '9') {
			i := 1
			for s[i] >= '0' && s[i] <= '9' {
				i++
			}
			num, _ := strconv.Atoi(s[:i])
			cur.t = Number
			cur.n = num
			left = s[i:]
		} else {
			error("-/0-9", s[:1], Number)
		}
	}
	return
}

func q1(f *os.File) {
	raw, _ := ioutil.ReadAll(f)
	r, _ := parser(strings.TrimSpace(string(raw)))
	fmt.Println(sum(r, ""))
	fmt.Println(sum(r, "red"))
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
}
