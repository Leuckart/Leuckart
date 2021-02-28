/**************************************************
	> File Name:  squares.go
	> Author:     Leuckart
	> Time:       2021-01-24 11:26
**************************************************/

package main

import "fmt"

func squares() func() int {
	var x int
	return func() int {
		x++
		return x * x
	}
}

func main() {
	f := squares()
	fmt.Printf("%T\n", f)

	fmt.Println(f())
	fmt.Println(f())
	fmt.Println(f())
	fmt.Println(f())
}
