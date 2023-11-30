package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// var cin = bufio.NewReader(os.Stdin)
var cout = bufio.NewWriter(os.Stdout)

func main() {

	ans, e := strconv.Atoi("-5")
	fmt.Fprintln(cout, ans, e)

	cout.Flush()
}