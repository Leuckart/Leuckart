/**************************************************
	> File Name:  findlinks.go
	> Author:     Leuckart
	> Time:       2021-01-24 11:13
**************************************************/

package main

import (
	"fmt"
	"log"
	"os"

	"ch_05/06_links"
)

// 对 worklist 逐元素调用 f, 并对 f 的返回值递归调用 f
func breadthFirst(f func(item string) []string, worklist []string) {
	seen := make(map[string]bool)
	for len(worklist) > 0 {
		items := worklist
		worklist = nil
		for _, item := range items {
			if !seen[item] {
				seen[item] = true
				worklist = append(worklist, f(item)...)
			}
		}
	}
}

func crawl(url string) []string {
	fmt.Println(url)
	list, err := links.Extract(url)
	if err != nil {
		log.Print(err)
	}
	return list
}

// ./findlinks https://golang.google.cn
func main() {
	breadthFirst(crawl, os.Args[1:])
}
