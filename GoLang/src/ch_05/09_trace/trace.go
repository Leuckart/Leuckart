/**************************************************
	> File Name:  trace.go
	> Author:     Leuckart
	> Time:       2021-01-24 23:26
**************************************************/

package main

import (
	"log"
	"time"
)

func bigSlowOperation() {
	defer trace("bigSlowOperation")()
	time.Sleep(1 * time.Second)
}

func trace(msg string) func() {
	start := time.Now()
	log.Printf("enter %s", msg)
	return func() { log.Printf("exit %s (%s)", msg, time.Since(start)) }
}

func main() {
	bigSlowOperation()
}
