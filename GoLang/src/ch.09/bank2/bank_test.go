/**************************************************
	> File Name:  bank_test.go
	> Author:     Leuckart
	> Time:       2021-01-27 19:35
**************************************************/

package bank_test

import (
	"./bank"
	"sync"
	"testing"
)

func TestBank(t *testing.T) {
	var n sync.WaitGroup
	for i := 1; i <= 1000; i++ {
		n.Add(1)
		go func(amount int) {
			bank.Deposit(amount)
			n.Done()
		}(i)
	}
	n.Wait()

	if got, want := bank.Balance(), (1000+1)*1000/2; got != want {
		t.Errorf("Balance = %d, want %d", got, want)
	}
}
