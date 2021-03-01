/**************************************************
	> File Name:  echo3.go
	> Author:     Leuckart
	> Time:       2021-01-13 15:59
**************************************************/

package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	fmt.Println(strings.Join(os.Args[1:], ", "))
}
