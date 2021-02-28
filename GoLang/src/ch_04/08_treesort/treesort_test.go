/**************************************************
	> File Name:  treesort_test.go
	> Author:     Leuckart
	> Time:       2021-01-18 17:38
**************************************************/

package treesort_test

import (
	"math/rand"
	"sort"
	"testing"

	"ch_04/08_treesort"
)

func TestSort(t *testing.T) {
	data := make([]int, 50)
	for i := range data {
		data[i] = rand.Int() % 50
	}

	treesort.Sort(data)
	if !sort.IntsAreSorted(data) {
		t.Errorf("not sorted: %v", data)
	}
}
