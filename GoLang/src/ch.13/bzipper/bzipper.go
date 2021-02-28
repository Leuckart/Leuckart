/**************************************************
	> File Name:  bzipper.go
	> Author:     Leuckart
	> Time:       2021-02-01 02:38
**************************************************/

package main

import (
	"./bzip"
	"io"
	"log"
	"os"
)

func main() {
	w := bzip.NewWriter(os.Stdout)
	if _, err := io.Copy(w, os.Stdin); err != nil {
		log.Fatalf("bzipper: %v\n", err)
	}
	if err := w.Close(); err != nil {
		log.Fatalf("bzipper: close: %v\n", err)
	}
}
