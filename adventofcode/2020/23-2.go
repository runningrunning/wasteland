// just a simple double link list, sooooooo easier ~~~~
// use the proper data structure is the easiest way
// TODO use go list

package main

import (
	"fmt"
)

type El struct {
	next, prev *El
	value      int
	l       *List
}

type List struct {
	root El
}

func (e *El) Next() *El {
	// skip root
	// fmt.Print(e, e.next, e.l)
	if e.next == &e.l.root {
		return e.l.root.next
	}
	return e.next
}

func (e *El) Insert(a *El) {
	a.prev = e
	a.next = e.next
	e.next.prev = a
	e.next = a
}

func (e *El) Remove() *El {
	e.prev.next = e.next
	e.next.prev = e.prev
	return e
}

func (l *List) Push(v int) *El {
	e := new(El)
	e.value = v
	e.prev = l.root.prev
	l.root.prev.next = e
	e.next = &l.root
	l.root.prev = e
	e.l = l

	if v > max {
		max = v
	}

	if v < min {
		min = v
	}

	// cache
	cache[v] = e
	return e
}

func NewList() *List {
	l := new(List)
	l.root.prev, l.root.next = &l.root, &l.root
	l.root.value = 0
	l.root.l = l
	return l
}

func (l *List) Output() {
	for p := l.root.next; p != &l.root; p = p.next {
		fmt.Print(p.value, ",")
	}
	fmt.Println()
	// for p := l.root.prev; p != &l.root; p = p.prev {
	// 	fmt.Print(p.value, ",")
	// }
	// fmt.Println()
}

var max,min int
var cache map[int]*El

func q1(l *List, t int) {
	e := l.root.Next()

	for i := 0; i < t; i ++ {
		// fmt.Println(i)
		e1 := e.Next().Remove()
		e2 := e.Next().Remove()
		e3 := e.Next().Remove()

		// fmt.Println(e1.value, e2.value, e3.value)
		// l.Output()

		c := e.value - 1
		for {
			if c < min {
				c = max
			}

			if c != e1.value && c != e2.value && c != e3.value {
				break
			}
			c -= 1
		}

		cache[c].Insert(e1)
		e1.Insert(e2)
		e2.Insert(e3)
		// l.Output()
		e = e.Next()
		// fmt.Print(e.value)
	}

	fmt.Println(cache[1].Next().value, cache[1].Next().Next().value)
	fmt.Println(cache[1].Next().value * cache[1].Next().Next().value)
}

func main() {
	l := NewList()
	cache = make(map[int]*El)
	// input := []int{3, 8, 9, 1, 2, 5, 4, 6, 7}
	input := []int{1,9,8,7,5,3,4,6,2}
	// m, n := 100, 50
	m, n := 1000000, 10000000

	max = 0
	min = m

	for _, x := range input {
		l.Push(x)
	}

	for i := 10; i <= m; i ++ {
		l.Push(i)
	}

	// l.Output()
	q1(l, n)
}
