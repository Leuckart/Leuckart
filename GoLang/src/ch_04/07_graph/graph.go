/**************************************************
	> File Name:  graph.go
	> Author:     Leuckart
	> Time:       2021-01-18 17:06
**************************************************/

package main

import "fmt"

var graph = make(map[string](map[string]bool))

func addEdge(from, to string) {
	if graph[from] == nil {
		graph[from] = make(map[string]bool)
	}
	graph[from][to] = true
}

func hasEdge(from, to string) bool {
	return graph[from][to]
}

func main() {
	addEdge("a", "b")
	addEdge("c", "d")
	addEdge("a", "d")
	addEdge("d", "a")

	fmt.Println(hasEdge("a", "b"))
	fmt.Println(hasEdge("c", "d"))
	fmt.Println(hasEdge("a", "d"))
	fmt.Println(hasEdge("d", "a"))

	fmt.Println(hasEdge("x", "b"))
	fmt.Println(hasEdge("x", "d"))
	fmt.Println(hasEdge("d", "x"))
}
