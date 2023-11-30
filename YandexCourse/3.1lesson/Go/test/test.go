package main

import (
	"fmt"
	"bufio"
	"os"
)

// var cin = bufio.NewReader(os.Stdin)
var cout = bufio.NewWriter(os.Stdout)

func main() {
	a := make([]interface{}, 0, 5)
	a = append(a, 15)
	a = append(a, "Blyat")
	a = append(a, true)
	a = append(a, 1000.7)

	for i := range a {
		fmt.Fprintf(cout, "%v : %T\n", a[i], a[i])
	}
	cout.Flush()
}