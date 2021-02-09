// graph problem
// try list/stack/heap
// introduce the visited position will make it's simpler
// try use PriorityQueue from heap

package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

type IntHeap []int64

func (h IntHeap) Len() int         { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int64))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func char(x, y int, m [][]byte) bool {
	if x < 0 || x >= len(m) || y < 0 || y >= len(m[0]) {
		return false
	}

	if m[x][y] >= 'A' && m[x][y] <= 'Z' {
		return true
	}
	return false
}

func block(x, y int, m [][]byte) bool {
	if x < 0 || x >= len(m) || y < 0 || y >= len(m[0]) {
		return true
	}
	return m[x][y] == '#' || m[x][y] == ' '
}

func portal(x, y int, m [][]byte) []int {
	// don't process the outer
	if x == 0 || x == len(m)-1 || y == 0 || y == len(m[0])-1 {
		return nil
	}

	if !char(x, y, m) {
		return nil
	}

	if char(x-1, y, m) {
		return []int{x - 1, y, x, y}
	}

	if char(x, y-1, m) {
		return []int{x, y - 1, x, y}
	}

	if char(x+1, y, m) {
		return []int{x, y, x + 1, y}
	}

	if char(x, y+1, m) {
		return []int{x, y, x, y + 1}
	}
	return nil
}

func name(p []int, m [][]byte, recursive bool) string {
	name := string([]byte{m[p[0]][p[1]], m[p[2]][p[3]]})
	if recursive {
		if p[0] == 0 || p[1] == 0 || p[2] == len(m)-1 || p[3] == len(m[0])-1 {
			return name + "0"
		}
		return name + "1"
	}
	return name
}

func visit(px, py int, m [][]byte, recursive bool) (string, map[string]int) {
	// don't process the outer
	p := portal(px, py, m)

	if p == nil {
		return "", nil
	}

	src := name(p, m, recursive)
	path := make(map[string]int)

	st := make([]int, len(m)*len(m[0]))
	nx := make([]int, len(m)*len(m[0]))

	sn := 0
	nn := 0

	step := -1

	st[sn] = p[0]<<16 | p[1]
	sn++
	st[sn] = p[2]<<16 | p[3]
	sn++

	visited := make([][]bool, len(m))
	for i := range visited {
		visited[i] = make([]bool, len(m[0]))
	}

	for sn != 0 {
		for i := 0; i < sn; i++ {
			t := st[i]
			x, y := t>>16, t&0xFFFF

			if visited[x][y] {
				continue
			}

			visited[x][y] = true

			if char(x, y, m) {
				// fmt.Println(x, y)
				if (x != p[0] || y != p[1]) && (x != p[2] || y != p[3]) {
					if d := portal(x, y, m); d != nil {
						des := name(d, m, recursive)
						if path[des] == 0 {
							path[des] = step - 1
						}
					}
				}
			}

			if !block(x-1, y, m) {
				nx[nn] = (x-1)<<16 | y
				nn++
			}

			if !block(x, y-1, m) {
				nx[nn] = x<<16 | y - 1
				nn++
			}

			if !block(x+1, y, m) {
				nx[nn] = (x+1)<<16 | y
				nn++
			}

			if !block(x, y+1, m) {
				nx[nn] = x<<16 | y + 1
				nn++
			}

		}

		// fmt.Println(sn, nn)

		st, nx = nx, st
		sn = nn
		nn = 0
		step++
	}

	// fmt.Println(src, path)
	return src, path
}

func output(maze [][]byte) {
	for _, x := range maze {
		fmt.Println(string(x))
	}
	fmt.Println()
}

func parser(f *os.File, recursive bool) map[string]map[string]int {
	var out [][]byte
	input := bufio.NewScanner(f)
	for input.Scan() {
		out = append(out, []byte(input.Text()))
	}

	path := make(map[string]map[string]int)

	for x, ys := range out {
		for y, _ := range ys {
			if char(x, y, out) {
				if s, p := visit(x, y, out, recursive); s != "" {
					// fmt.Println(s, p)
					if path[s] == nil {
						path[s] = make(map[string]int)
					}
					for n, _ := range p {
						if path[n] == nil {
							path[n] = make(map[string]int)
						}

						l, ok := path[s][n]

						if !ok || l > p[n] {
							path[s][n] = p[n]
						}

						l, ok = path[n][s]

						if !ok || l > p[n] {
							path[n][s] = p[n]
						}
					}
				}
			}
		}
	}
	return path
}

func q1(f *os.File) {
	path := parser(f, false)
	// fmt.Println(path)

	for {
		found := false
		for src, des := range path {
			for d := range des {
				for dds := range path[d] {
					if dds == src {
						continue
					}
					if path[src][dds] == 0 || (path[src][dds] > path[src][d]+path[d][dds]+1) {
						path[src][dds] = path[src][d] + path[d][dds] + 1
						path[dds][src] = path[src][d] + path[d][dds] + 1
						found = true
					}
				}
			}
		}

		if !found {
			break
		}
	}
	// fmt.Println(path)
	fmt.Println(path["AA"]["ZZ"])
}

func q2(f *os.File) {
	path := parser(f, true)
	fmt.Println(path)

	sti := make(map[string]int64)
	ids := make([]string, 0, len(path))

	index := int64(0)
	for ps := range path {
		ids = append(ids, ps)
		sti[ps] = index
		index++
	}

	// fmt.Println(its, ids)
	h := &IntHeap{}
	heap.Init(h)
	// steps << 32 | current | level
	heap.Push(h, 0<<32|sti["AA0"]<<16|0)
	steps := int64(1000000000)
	for {
		x := heap.Pop(h).(int64)
		cstep := x >> 32
		cstr := ids[(x&0xFFFF0000)>>16]
		clevel := x & 0xFFFF

		// fmt.Println(cstep, cstr, clevel, steps)

		if cstep > steps {
			break
		}

		if clevel == 0 {
			// try go to ZZ0
			for nxt, _ := range path[cstr] {
				l := int64(path[cstr][nxt])
				if nxt == "ZZ0" {
					if steps > cstep + l {
						steps = cstep + l
					}
				}
				if nxt[2] == '0' {
					continue
				}
				heap.Push(h, (cstep + l + 1)<< 32 | sti[nxt[:2]+"0"]<<16|1)
			}
		} else {
			for nxt, _ := range path[cstr] {
				l := int64(path[cstr][nxt])
				if nxt == "ZZ0" || nxt == "AA0" {
					continue
				}

				if nxt[2] == '0' {
					heap.Push(h, (cstep+l+1)<<32|sti[nxt[:2]+"1"]<<16|clevel-1)
				} else {
					heap.Push(h, (cstep+l+1)<<32|sti[nxt[:2]+"0"]<<16|clevel+1)
				}

			}
		}
	}

	fmt.Println(steps)
}

func main() {
	f, _ := os.Open(os.Args[1])
	defer f.Close()
	q1(f)
	f.Seek(0, 0)
	q2(f)
}
