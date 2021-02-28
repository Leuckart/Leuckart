/**************************************************
	> File Name:  outline.go
	> Author:     Leuckart
	> Time:       2021-01-24 03:39
**************************************************/

package main

import (
	"fmt"
	"os"

	"golang.org/x/net/html"
)

func outline(stack []string, n *html.Node) {
	if n.Type == html.ElementNode {
		stack = append(stack, n.Data)
		fmt.Println(stack)
	}
	for c := n.FirstChild; c != nil; c = c.NextSibling {
		outline(stack, c)
	}
}

// ../../ch_01/05_fetch/fetch https://golang.google.cn | ./outline
func main() {
	doc, err := html.Parse(os.Stdin)
	if err != nil {
		fmt.Fprintf(os.Stderr, "outline: %v\n", err)
		os.Exit(1)
	}
	outline(nil, doc)
}
