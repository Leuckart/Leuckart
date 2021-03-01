/**************************************************
	> File Name:  popcount.go
	> Author:     Leuckart
	> Time:       2021-01-17 03:12
**************************************************/

package popcount

var popCount [256]byte

func init() {
	for i, _ := range popCount {
		popCount[i] = popCount[i/2] + byte(i&1)
	}
}

func PopCount(x uint64) int {
	return int(popCount[byte(x>>(0*8))] +
		popCount[byte(x>>(1*8))] +
		popCount[byte(x>>(2*8))] +
		popCount[byte(x>>(3*8))] +
		popCount[byte(x>>(4*8))] +
		popCount[byte(x>>(5*8))] +
		popCount[byte(x>>(6*8))] +
		popCount[byte(x>>(7*8))])
}
