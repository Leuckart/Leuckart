/**************************************************
	> File Name:  countdown.go
	> Author:     Leuckart
	> Time:       2021-01-26 14:38
**************************************************/

package main

import (
	"fmt"
	"os"
	"time"
)

func launch() {
	fmt.Println("Lift off!")
}

func aborts() {
	fmt.Println("Launch aborted!")
}

func main() {
	abort := make(chan struct{})
	go func() {
		os.Stdin.Read(make([]byte, 1))
		abort <- struct{}{}
	}()

	fmt.Println("Commencing countdown.  Press return to abort.")
	select {
	case <-time.After(10 * time.Second):
		launch()
	case <-abort:
		aborts()
	}
}
