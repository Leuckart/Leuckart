/**************************************************
	> File Name:  unsafeptr.go
	> Author:     Leuckart
	> Time:       2021-02-01 03:00
**************************************************/

package main

import (
	"fmt"
	"unsafe"
)

func main() {
	var x struct {
		a bool
		b int16
		c []int
	}

	pb := (*int16)(unsafe.Pointer(
		uintptr(unsafe.Pointer(&x)) + unsafe.Offsetof(x.b)))
	*pb = 42
	fmt.Println(x.b)
}
