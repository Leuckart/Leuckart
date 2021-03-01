/**************************************************
	> File Name:  ftoc.go
	> Author:     Leuckart
	> Time:       2021-01-15 20:38
**************************************************/

package main

import "fmt"

func main() {
	const freezingF, boilingF = 32.0, 212.0
	fmt.Printf("%g(F) = %g(C)\n", freezingF, fToC(freezingF))
	fmt.Printf("%g(F) = %g(C)\n", boilingF, fToC(boilingF))
}

func fToC(f float64) float64 {
	return (f - 32.0) * 5.0 / 9.0
}
