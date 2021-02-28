/**************************************************
	> File Name:  defer.go
	> Author:     Leuckart
	> Time:       2021-01-24 03:12
**************************************************/

package main

import "fmt"

func f(x int) {
	defer fmt.Printf("defer | x = %d\n", x)
	fmt.Printf("entering f(%d)\n", x+0/x)
	f(x - 1)
}

func main() {
	f(3)
}
