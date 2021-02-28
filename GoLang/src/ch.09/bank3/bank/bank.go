/**************************************************
	> File Name:  bank.go
	> Author:     Leuckart
	> Time:       2021-01-27 19:41
**************************************************/

package bank

import "sync"

var (
	mu      sync.Mutex
	balance int
)

func Deposit(amount int) {
	mu.Lock()
	balance += amount
	mu.Unlock()
}

func Balance() int {
	mu.Lock()
	b := balance
	mu.Unlock()
	return b
}
