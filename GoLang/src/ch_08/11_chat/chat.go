/**************************************************
	> File Name:  chat.go
	> Author:     Leuckart
	> Time:       2021-01-26 02:05
**************************************************/

package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
)

type client chan<- string

var (
	entering = make(chan client)
	leaving  = make(chan client)
	message  = make(chan string)
)

func broadcaster() {
	clients := make(map[client]bool)
	for {
		select {
		case msg := <-message: // 监听 messages 的消息, 并广播给所有客户
			for cli := range clients {
				cli <- msg
			}
		case cli := <-entering: // 更新 clients 集合
			clients[cli] = true
		case cli := <-leaving: // 更新 clients 集合, 并关闭客户对外发送消息的通道
			delete(clients, cli)
			close(cli)
		}
	}
}

func clientWriter(conn net.Conn, ch <-chan string) {
	for msg := range ch {
		fmt.Fprintln(conn, msg)
	}
}

func handleConn(conn net.Conn) {
	ch := make(chan string)
	go clientWriter(conn, ch)

	who := conn.RemoteAddr().String()
	ch <- "You are " + who
	message <- who + " has arrived"
	entering <- ch

	input := bufio.NewScanner(conn)
	for input.Scan() {
		message <- who + ": " + input.Text()
	}

	leaving <- ch
	message <- who + " has left"
	conn.Close()
}

// $ ./chat &
// $ ../03_netcat3/netcat		$ ../03_netcat3/netcat
// Hi!							$ Hi yourself!
func main() {
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}

	go broadcaster()
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}
