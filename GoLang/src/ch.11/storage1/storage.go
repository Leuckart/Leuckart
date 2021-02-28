/**************************************************
	> File Name:  storage.go
	> Author:     Leuckart
	> Time:       2021-01-28 02:41
**************************************************/

package storage

import (
	"fmt"
	"log"
	"net/smtp"
)

var usage = make(map[string]int64)

func bytesInUse(username string) int64 { return usage[username] }

const (
	sender   = "notifications@example.com"
	password = "correcthorsebatterystaple"
	hostname = "smtp.example.com"
	template = `Warning: you are using %d bytes of storage, %d%% of your quota.`
)

func CheckQuota(username string) {
	used := bytesInUse(username)
	const quota = 1e9
	percent := 100 * used / quota
	if percent < 90 {
		return
	}
	msg := fmt.Sprintf(template, used, percent)
	auth := smtp.PlainAuth("", sender, password, hostname)
	err := smtp.SendMail(hostname+":587", auth, sender, []string{username}, []byte(msg))
	if err != nil {
		log.Printf("smtp.SendMail(%s) failed: %s", username, err)
	}
}
