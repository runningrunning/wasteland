/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package popcount

var pc [256]byte

func init() {
    for i := range pc {
        pc[i] = pc[i/2] + byte(i&1)
    }
}

func PopCount(x uint64) int {
    return int(pc[byte(x>>(0*8))] +
        pc[byte(x>>(1*8))] +
        pc[byte(x>>(2*8))] +
        pc[byte(x>>(3*8))] +
        pc[byte(x>>(4*8))] +
        pc[byte(x>>(5*8))] +
        pc[byte(x>>(6*8))] +
        pc[byte(x>>(7*8))])
}

func PopCountLoop(x uint64) int {
    r := 0
    for i := 0; i < 8; i++ {
        r += int(pc[byte(x)])
        x >>= 8
    }
    return r
}

func PopCountShift(x uint64) int {
    r := 0
    for i := 0; i < 64; i++ {
        r += int(x & 0x1)
        x >>= 1
    }
    return r
}

func PopCountOr(x uint64) int {
    r := 0
    for x != 0 {
        x = x & (x - 1)
        r++
    }
    return r
}
