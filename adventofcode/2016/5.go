// my own md5, it's 5x times slower
// Must be careful
package main

import (
	"crypto/md5"
	"fmt"
	"strconv"
)

// implement MD5 here
// https://en.wikipedia.org/wiki/MD5
func _md5(msg []byte) []byte {

	S := []int{7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
		5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
		6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21}

	K := []uint32{
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391}

	a0 := uint32(0x67452301)
	b0 := uint32(0xefcdab89)
	c0 := uint32(0x98badcfe)
	d0 := uint32(0x10325476)

	inlen := len(msg)

	l := 64 - (inlen % 64)

	if l <= 8 {
		l += 64
	}

	msg = append(msg, 0x80)

	for i := 1; i < l-8; i++ {
		msg = append(msg, 0)
	}

	buflen := uint64(inlen * 8)

	for i := 0; i < 8; i++ {
		msg = append(msg, byte(buflen&0xFF))
		buflen >>= 8
	}

	for i := 0; i < len(msg); i += 64 {
		M := msg[i:]
		A := a0
		B := b0
		C := c0
		D := d0

		var F uint32
		var g int

		for k := 0; k < 64; k++ {
			if k < 16 {
				F = (B & C) | ((^B) & D)
				g = k
			} else if k < 32 {
				F = (D & B) | ((^D) & C)
				g = 5*k + 1
			} else if k < 48 {
				F = B ^ C ^ D
				g = 3*k + 5
			} else {
				F = C ^ (B | (^D))
				g = 7 * k
			}

			g %= 16

			F = F + A + K[k] + uint32(M[g*4]) + uint32(M[g*4+1])<<8 + uint32(M[g*4+2])<<16 + uint32(M[g*4+3])<<24
			A = D
			D = C
			C = B
			B = B + ((F << S[k]) | (F >> (32 - S[k])))
		}

		a0 = (a0 + A) & 0xFFFFFFFF
		b0 = (b0 + B) & 0xFFFFFFFF
		c0 = (c0 + C) & 0xFFFFFFFF
		d0 = (d0 + D) & 0xFFFFFFFF
	}

	return []byte{byte(a0 & 0xFF), byte((a0 >> 8) & 0xFF), byte((a0 >> 16) & 0xFF), byte((a0 >> 24) & 0xFF),
		byte(b0 & 0xFF), byte((b0 >> 8) & 0xFF), byte((b0 >> 16) & 0xFF), byte((b0 >> 24) & 0xFF),
		byte(c0 & 0xFF), byte((c0 >> 8) & 0xFF), byte((c0 >> 16) & 0xFF), byte((c0 >> 24) & 0xFF),
		byte(d0 & 0xFF), byte((d0 >> 8) & 0xFF), byte((d0 >> 16) & 0xFF), byte((d0 >> 24) & 0xFF)}
}

func q1(in string) {
	password := ""
	i := 0

	for len(password) < 8 {
		hash := md5.Sum([]byte(in + strconv.Itoa(i)))
		// hash := _md5([]byte(in + strconv.Itoa(i)))
		if hash[0] == 0 && hash[1] == 0 && hash[2] < 16 {
			if hash[2] < 10 {
				password += string(hash[2] + '0')
			} else {
				password += string(hash[2] - 10 + 'a')
			}
		}

		i++
	}
	fmt.Println(password)
}

func q2(in string) {
	password := make(map[byte]string)
	i := 0

	for len(password) < 8 {
		hash := md5.Sum([]byte(in + strconv.Itoa(i)))
		// hash := _md5([]byte(in + strconv.Itoa(i)))
		if hash[0] == 0 && hash[1] == 0 && hash[2] < 8 && password[hash[2]] == "" {
			t := fmt.Sprintf("%x", hash)
			// the 7th is index 6 !
			password[hash[2]] = string(t[6])
		}
		i++
	}

	real := ""
	for i := 0; i < 8; i++ {
		real += password[byte(i)]
	}

	fmt.Println(real)
}

func main() {
	q1("abc")
	q1("ojvtpuvg")
	q2("abc")
	q2("ojvtpuvg")
}
