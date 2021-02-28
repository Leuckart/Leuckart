/**************************************************
	> File Name:  urlvalues.go
	> Author:     Leuckart
	> Time:       2021-01-25 03:16
**************************************************/

package main

import (
	"fmt"
	"net/url"
)

func main() {
	m := url.Values{"lang": {"en"}}
	m.Add("item", "1")
	m.Add("item", "2")

	fmt.Println(m.Get("lang"))
	fmt.Println(m.Get("q"))
	fmt.Println(m.Get("item"))
	fmt.Println(m["item"])

	m = nil
	fmt.Println(m.Get("item"))
	m.Add("item", "3")
}
