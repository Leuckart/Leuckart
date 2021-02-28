/**************************************************
	> File Name:  issues.go
	> Author:     Leuckart
	> Time:       2021-01-18 18:36
**************************************************/

package main

import (
	"fmt"
	"log"
	"os"

	"ch_04/11_github"
)

// ./issues repo:golang/go is:open json decoder
func main() {
	result, err := github.SearchIssues(os.Args[1:])
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%d issues:\n", result.TotalCount)
	for _, item := range result.Items {
		fmt.Printf("#%-5d %9.9s %.55s\n", item.Number, item.User.Login, item.Title)
	}
}
