/**************************************************
	> File Name:  bytecounter.go
	> Author:     Leuckart
	> Time:       2021-01-25 04:06
**************************************************/

package main

import "fmt"

type ByteCounter int

func (c *ByteCounter) Write(p []byte) (int, error) {
	*c += ByteCounter(len(p))
	return len(p), nil
}

func (c ByteCounter) String() string {
	return fmt.Sprintf("value: %d", int(c))
}

func main() {
	var c ByteCounter
	c.Write([]byte("hello"))
	fmt.Println(c)

	c = 0
	var name = "Dolly"
	fmt.Fprintf(&c, "hello, %s", name)
	fmt.Println(c)
}
