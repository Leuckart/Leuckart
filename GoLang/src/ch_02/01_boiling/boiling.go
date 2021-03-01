/**************************************************
	> File Name:  boiling.go
	> Author:     Leuckart
	> Time:       2021-01-15 20:35
**************************************************/

package main

import "fmt"

const boilingF = 212.0

func main() {
	var f = boilingF
	var c = (f - 32) * 5 / 9
	fmt.Printf("boiling point = %g(F) or %g(C)\n", f, c)
}
