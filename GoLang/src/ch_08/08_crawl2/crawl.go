/**************************************************
	> File Name:  crawl.go
	> Author:     Leuckart
	> Time:       2021-01-26 22:02
**************************************************/

package main

import (
	"fmt"
	"log"
	"os"

	"ch_05/06_links"
)

var tokens = make(chan struct{}, 20)

func crawl(url string) []string {
	fmt.Println(url)
	tokens <- struct{}{}
	list, err := links.Extract(url)
	<-tokens

	if err != nil {
		log.Print(err)
	}
	return list
}

// ./crawl https://gopl.io/
func main() {
	worklist := make(chan []string)
	go func() { worklist <- os.Args[1:] }()
	var n int
	n++

	seen := make(map[string]bool)
	for ; n > 0; n-- {
		list := <-worklist
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				n++
				go func(link string) {
					worklist <- crawl(link)
				}(link)
			}
		}
	}
}
