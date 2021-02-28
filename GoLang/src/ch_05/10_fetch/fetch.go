/**************************************************
	> File Name:  fetch.go
	> Author:     Leuckart
	> Time:       2021-01-24 03:33
**************************************************/

package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
	"path"
)

func fetch(url string) (filename string, n int64, err error) {
	resp, err := http.Get(url)
	if err != nil {
		return "", 0, err
	}
	defer resp.Body.Close()

	local := path.Base(resp.Request.URL.Path)
	if local == "/" {
		local = "index.html"
	}
	f, err := os.Create(local)
	if err != nil {
		return "", 0, err
	}

	n, err = io.Copy(f, resp.Body)
	if closeErr := f.Close(); err == nil {
		err = closeErr // 若 io.Copy 与 f.Close 同时失败, 则优先报告 io.Copy 的错误信息
	}
	return local, n, err
}

// ./fetch https://golang.google.cn/
// ./fetch https://golang.google.cn/doc/effective_go.html
// ./fetch https://golang.google.cn/doc/gopher/frontpage.png
func main() {
	for _, url := range os.Args[1:] {
		local, n, err := fetch(url)
		if err != nil {
			fmt.Fprintf(os.Stderr, "fetch %s: %v\n", url, err)
			continue
		}
		fmt.Fprintf(os.Stderr, "%s => %s (%d bytes).\n", url, local, n)
	}
}
