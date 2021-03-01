/**************************************************
	> File Name:  echo2.go
	> Author:     Leuckart
	> Time:       2021-01-13 15:56
**************************************************/

package main

import (
	"fmt"
	"os"
)

func main() {
	s, sep := "", ""
	for _, arg := range os.Args[1:] {
		s += sep + arg
		sep = ", "
	}
	fmt.Println(s)
}
