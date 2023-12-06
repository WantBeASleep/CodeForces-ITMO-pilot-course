package main

import (
	"fmt"
	"bufio"
	"os"
)

var cin = bufio.NewReader(os.Stdin)
var cout = bufio.NewWriter(os.Stdout)

func main() {
	var n, m int
	fmt.Fscan(cin, &n, &m)

	g := make([][]int, n + 1)
	for i := 0; i != n + 1; i++ {
		g[i] = make([]int, 0)
	}

	for i := 0; i != m; i++ {
		var v1, v2 int
		fmt.Fscan(cin, &v1, &v2)

		g[v1] = append(g[v1], v2)
	}

	

	cout.Flush()
}