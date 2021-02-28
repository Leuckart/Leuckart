/**************************************************
	> File Name:  memo_test.go
	> Author:     Leuckart
	> Time:       2021-01-27 19:46
**************************************************/

package memo_test

import (
	"./memo"
	"./memotest"
	"testing"
)

var httpGetBody = memotest.HTTPGetBody

func Test(t *testing.T) {
	m := memo.New(httpGetBody)
	memotest.Sequential(t, m)
}

func TestConcurrent(t *testing.T) {
	m := memo.New(httpGetBody)
	memotest.Concurrent(t, m)
}
