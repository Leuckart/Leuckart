/**************************************************
	> File Name:  main.go
	> Author:     Leuckart
	> Time:       2021-01-27 01:46
**************************************************/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"

	"ch_08/07_thumbnail/thumbnail"
)

// entering: ../../../doc/fiveyears.jpg
func main() {
	input := bufio.NewScanner(os.Stdin)
	for input.Scan() {
		thumb, err := thumbnail.ImageFile(input.Text())
		if err != nil {
			log.Print(err)
			continue
		}
		fmt.Println(thumb)
	}
	if err := input.Err(); err != nil {
		log.Fatal(err)
	}
}
