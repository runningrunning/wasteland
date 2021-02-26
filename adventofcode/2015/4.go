package main

import (
	"crypto/md5"
	"fmt"
	"strconv"
)

func q1(salt string) {
	i := 1
	for {
		hash := md5.Sum([]byte(salt + strconv.Itoa(i)))
		// hash[2] < 16 5 zeros
		// hash[2] == 0 6 zeros
		if hash[0] == 0 && hash[1] == 0 && hash[2] == 0 {
			fmt.Println(i)
			break
		}
		i++
	}
}

func main() {
	q1("abcdef")
	q1("pqrstuv")
	q1("yzbqklnj")
}
