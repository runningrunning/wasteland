package main

import (
	"fmt"
)

func main() {
	const (
		_K  = 1000
		KB = _K
		MB = KB * _K
		GB = MB * _K
		TB = GB * _K
		PB = TB * _K
		EB = PB * _K
		ZB = EB * _K
		YB = ZB * _K
	)
	fmt.Printf("%v %v %v\n", KB, PB, YB)
}
