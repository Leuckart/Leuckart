/**************************************************
	> File Name:  comma.go
	> Author:     Leuckart
	> Time:       2021-01-17 20:12
**************************************************/

package main

import (
	"fmt"
	"os"
)

func comma(s string) string {
	n := len(s)
	if n <= 3 {
		return s
	}
	return comma(s[:n-3]) + "," + s[n-3:]
}

func main() {
	for i := 1; i < len(os.Args); i++ {
		fmt.Printf(" %s\n", comma(os.Args[i]))
	}
}
