/**************************************************
	> File Name:  nonempty.go
	> Author:     Leuckart
	> Time:       2021-01-17 22:27
**************************************************/

package main

import "fmt"

// Slice 的本质是 ptr + len + capacity, 因此可以修改输入的实参
func nonempty(strings []string) []string {
	i := 0
	for _, s := range strings {
		if s != "" {
			strings[i] = s
			i++
		}
	}
	return strings[:i]
}

/*
func nonempty(strings []string) []string {
	out := make([]string, 0)
	for _, s := range strings {
		if s != "" {
			out = append(out, s)
		}
	}
	return out
}
*/

func main() {
	data := []string{"one", "", "three"}
	fmt.Printf("%q\n", nonempty(data))
	fmt.Printf("%q\n", data)
}
