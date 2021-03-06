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

func launch() { fmt.Println("Lift off!") }

func aborts() { fmt.Println("Launch aborted!") }

func main() {
	abort := make(chan struct{})
	go func() {
		os.Stdin.Read(make([]byte, 1))
		abort <- struct{}{}
	}()

	fmt.Println("Commencing countdown.  Press return to abort.")
	tick := time.Tick(1 * time.Second)
	for countdown := 10; countdown > 0; countdown-- {
		fmt.Println(countdown)
		select {
		case <-tick:
			// Do nothing
		case <-abort:
			fmt.Println("Launch aborted!")
			return
		}
	}
	launch()
}
