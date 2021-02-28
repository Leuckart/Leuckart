/**************************************************
	> File Name:  utf8.go
	> Author:     Leuckart
	> Time:       2021-01-22 18:05
**************************************************/

package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	s := "Hello, 世界"
	fmt.Printf("% x\n", s)
	r := []rune(s) // 返回 UTF-8 字符串的 Unicode 码点序列
	fmt.Printf("%x\n", r)
	fmt.Println(string(r)) // string(r) 将 Unicode 码点 Slice 转换成字符串

	fmt.Println(len(s))                    // 13
	fmt.Println(utf8.RuneCountInString(s)) //9

	// UTF-8 解码器
	for i := 0; i < len(s); {
		r, size := utf8.DecodeRuneInString(s[i:])
		fmt.Printf("(%d) %c.\t", i, r)
		i += size
	}
	fmt.Println()

	// range 循环内解码
	for i, r := range s {
		fmt.Printf("(%d) %q %d.\t", i, r, r)
	}
	fmt.Println()
}
