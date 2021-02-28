/**************************************************
	> File Name:  defer.go
	> Author:     Leuckart
	> Time:       2021-01-24 03:14
**************************************************/

package main

import (
	"fmt"
	"os"
	"runtime"
)

func printStack() {
	var buf [4096]byte
	n := runtime.Stack(buf[:], false)
	os.Stdout.Write(buf[:n])
}

func f(x int) {
	defer fmt.Printf("defer | x = %d\n", x)
	fmt.Printf("entering f(%d)\n", x+0/x)
	f(x - 1)
}

func main() {
	defer printStack()
	f(3)
}
