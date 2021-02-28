/**************************************************
	> File Name:  cross.go
	> Author:     Leuckart
	> Time:       2021-01-27 23:18
**************************************************/

package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Println(runtime.GOOS, runtime.GOARCH)
}
