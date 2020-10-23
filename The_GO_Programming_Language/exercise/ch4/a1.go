package main

import (
	"crypto/sha256"
	"crypto/sha512"
	"fmt"
	"tgpl/popcount"
)

func main() {
	s1 := "x"
	s2 := "X"

	c1 := sha256.Sum256([]byte(s1))
	c2 := sha256.Sum256([]byte(s2))

	var d int = 0

	for i := 0; i < len(c1); i++ {
		d += popcount.PopCount8(c1[i] ^ c2[i])
	}

	fmt.Printf("c1 %x c2 %x diff is %d.\n", c1, c2, d)
	fmt.Printf("0x1 0x2 diff is %d.\n", popcount.PopCount8(0x1 ^ 0x2));
	fmt.Printf("0x1 0x3 diff is %d.\n", popcount.PopCount8(0x1 ^ 0x3));
	fmt.Printf("0x0 0x2 diff is %d.\n", popcount.PopCount8(0x0 ^ 0x2));

	fmt.Printf("%x sha256\n%x sha512/256\n%x sha224\n%x sha512/224\n",
		sha256.Sum256([]byte(s1)), sha512.Sum512_256([]byte(s1)),
		sha256.Sum224([]byte(s1)), sha512.Sum512_224([]byte(s1)));
}

