/**************************************************
	> File Name:  sleep.go
	> Author:     Leuckart
	> Time:       2021-01-25 04:09
**************************************************/

package main

import (
	"flag"
	"fmt"
	"time"
)

var period = flag.Duration("period", 1*time.Second, "sleep period")

func main() {
	flag.Parse()
	fmt.Printf("Sleeping for %v...", *period)
	time.Sleep(*period)
	fmt.Println()
}
