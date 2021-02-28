/**************************************************
	> File Name:  tempflag.go
	> Author:     Leuckart
	> Time:       2021-01-25 23:09
**************************************************/

package main

import (
	"flag"
	"fmt"

	"ch_07/03_tempconv"
)

var temp = tempconv.CelsiusFlag("temp", 20., "the temperature")

func main() {
	flag.Parse()
	fmt.Println(*temp)
}
