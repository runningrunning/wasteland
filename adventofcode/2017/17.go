// Find a easier calculation to find it. Q2
package main

import (
	"fmt"
)

type Node struct {
	value     int
	pre, next *Node
}

type List struct {
	root Node
	len  int
}

func (n *Node) Step(s int, l *List) *Node {
	if l.len == 0 {
		return &l.root
	}

	s %= l.len
	for i := 0; i < s; i++ {
		n = n.next
		if n == &l.root {
			n = n.next
		}
	}
	return n
}

func (l *List) Output() {
	s := l.root.next
	for {
		if s == &l.root {
			break
		}
		fmt.Printf("%d,", s.value)
		s = s.next
	}
	fmt.Println()
}

func q1(step int, number, seek int) int {
	list := new(List)
	list.root.pre = &list.root
	list.root.next = &list.root

	cur := &list.root
	for i := 0; i <= number; i++ {
		n := cur.Step(step, list)
		node := new(Node)
		node.value = i
		node.pre = n
		node.next = n.next
		n.next.pre = node
		n.next = node
		list.len += 1
		cur = node
	}

	// list.Output()

	cur = &list.root
	for {
		if cur == &list.root {
			cur = cur.next
		}

		if cur.value == seek {
			if cur.next == &list.root {
				return list.root.next.value
			}
			return cur.next.value
		}
		cur = cur.next
	}
	return -1
}

func q2(step int, number, seek int) int {
	list := new(List)
	list.root.pre = &list.root
	list.root.next = &list.root

	cur := &list.root
	for i:= 0; i <= seek; i ++ {
		n := cur.Step(step, list)
		node := new(Node)
		node.value = i
		node.pre = n
		node.next = n.next
		n.next.pre = node
		n.next = node
		list.len += 1
		cur = node
	}

	start, next, len := 0, 0, list.len

	for i := len; i <= number; i ++ {
		start = (start + (step % len)) % len
		if start == 0 {
			next = i
		}
		start += 1
		len += 1
	}

	return next
}

func main() {
	fmt.Println(q1(3, 2017, 2017))
	fmt.Println(q1(376, 2017, 2017))
	// 39289581, slow version
	// fmt.Println(q1(376, 50000000, 0))
	// 39289581, faster version
	fmt.Println(q2(376, 50000000, 0))
}
