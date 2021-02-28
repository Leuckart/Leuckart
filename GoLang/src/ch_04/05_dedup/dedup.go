/**************************************************
	> File Name:  dedup.go
	> Author:     Leuckart
	> Time:       2021-01-17 23:52
**************************************************/

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Go 无内置的集合类型, 所以使用 map[string]bool 作为替代
	seen := make(map[string]bool)
	input := bufio.NewScanner(os.Stdin)
	for input.Scan() {
		line := input.Text()
		if !seen[line] {
			seen[line] = true
			fmt.Println(line)
		}
	}

	if err := input.Err(); err != nil {
		fmt.Fprintf(os.Stderr, "dedup: %v\n", err)
		os.Exit(1)
	}
}
