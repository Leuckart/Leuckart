/**************************************************
	> File Name:  bank.go
	> Author:     Leuckart
	> Time:       2021-01-27 19:35
**************************************************/

package bank

var (
	sema    = make(chan struct{}, 1)
	balance int
)

func Deposit(amount int) {
	sema <- struct{}{}
	balance += amount
	<-sema
}

func Balance() int {
	sema <- struct{}{}
	b := balance
	<-sema
	return b
}
