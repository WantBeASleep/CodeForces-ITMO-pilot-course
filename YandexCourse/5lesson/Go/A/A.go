package main

import (
	"fmt"
	"bufio"
	"os"
)

func main() {
	var n, q int
	// reader := bufio.NewReader(os.Stdin)


	data := make([]int64, n)
	for i := 0; i != n; i++ {
		fmt.Scan(&data[i])
	}

	suff := make([]int64, n + 1)
	for i := 1; i != n + 1; i++ {
		suff[i] = suff[i - 1] + data[i - 1]
	}

	for i := 0; i != q; i++ {
		var l, r int
		fmt.Scan(&l, &r)
		l--
		fmt.Println(suff[r] - suff[l])
	}

}