/**************************************************
	> File Name:  methods_test.go
	> Author:     Leuckart
	> Time:       2021-01-28 22:20
**************************************************/

package methods

import (
	"./methods"
	"strings"
	"time"
)


func Example_printDuration() {
	methods.Print(time.Hour)
}

func Example_printReplacer() {
	methods.Print(new(strings.Replacer))
}
