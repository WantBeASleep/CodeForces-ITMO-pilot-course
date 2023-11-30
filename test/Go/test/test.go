package main

import (
	"fmt"
	"bufio"
	"os"
)

// var cin = bufio.NewReader(os.Stdin)
var cout = bufio.NewWriter(os.Stdout)

func main() {

	a := [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

	b := a[2:5]
	c := b[4:6]

	printSlice(b)
	printSlice(c)
	printArr(a)

	cout.Flush()
}

func printArr(arr [10]int) {
	fmt.Fprintf(cout, "Len %d; Cap %d; Arr: %v\n", len(arr), cap(arr), arr)
}

func printSlice(arr []int) {
	fmt.Fprintf(cout, "Len %d; Cap %d; Arr: %v\n", len(arr), cap(arr), arr)
}