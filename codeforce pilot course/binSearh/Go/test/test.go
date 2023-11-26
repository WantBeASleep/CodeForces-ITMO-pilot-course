package main

import (
	"fmt"
	"bufio"
	"os"
)

// var cin = bufio.NewReader(os.Stdin)
var cout = bufio.NewWriter(os.Stdout)

func main() {
	a := []int{1, 2, 3, 4}

	fmt.Fprintln(cout, a[4:]) // []
	fmt.Fprintln(cout, a[5:]) // panic slice bounds out of range [5:4]

	cout.Flush()
}