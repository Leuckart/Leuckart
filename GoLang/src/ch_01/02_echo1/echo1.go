/**************************************************
	> File Name:  echo1.go
	> Author:     Leuckart
	> Time:       2021-01-13 15:43
**************************************************/

package main

import (
	"fmt"
	"os"
)

func main() {
	var s, sep string
	for i := 1; i < len(os.Args); i++ {
		s += sep + os.Args[i]
		sep = ", "
	}
	fmt.Println(s)
}
