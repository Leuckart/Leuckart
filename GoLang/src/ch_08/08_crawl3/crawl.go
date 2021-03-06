/**************************************************
	> File Name:  crawl.go
	> Author:     Leuckart
	> Time:       2021-01-26 22:11
**************************************************/

package main

import (
	"fmt"
	"log"
	"os"

	"ch_05/06_links"
)

func crawl(url string) []string {
	fmt.Println(url)
	list, err := links.Extract(url)
	if err != nil {
		log.Print(err)
	}
	return list
}

// ./crawl https://gopl.io/
func main() {
	worklist := make(chan []string)
	go func() { worklist <- os.Args[1:] }()

	unseenLinks := make(chan string)
	for i := 0; i < 20; i++ {
		go func() {
			for link := range unseenLinks {
				foundLinks := crawl(link)
				go func() { worklist <- foundLinks }()
			}
		}()
	}

	seen := make(map[string]bool)
	for list := range worklist {
		for _, link := range list {
			if !seen[link] {
				seen[link] = true
				unseenLinks <- link
			}
		}
	}
}
