/**************************************************
	> File Name:  format_test.go
	> Author:     Leuckart
	> Time:       2021-01-28 20:28
**************************************************/

package format

import (
	"./format"
	"fmt"
	"testing"
	"time"
)

func Test(t *testing.T) {
	var x int64 = 1
	var d time.Duration = 1 * time.Nanosecond

	fmt.Println(format.Any(x))
	fmt.Println(format.Any(d))
	fmt.Println(format.Any([]int64{x}))
	fmt.Println(format.Any([]time.Duration{d}))
}
