package main

import (
	"bufio"
	"fmt"
	"os"
)

var cin = bufio.NewReader(os.Stdin)
var cout = bufio.NewWriter(os.Stdout)

func main() {
	var n, d int
	fmt.Fscan(cin, &n, &d)

	arr := make([]int, n)
	for i := 0; i != n; i++ {
		fmt.Fscan(cin, &arr[i])
	}

	left, right := bin(arr, d)
	fmt.Fprintln(cout, left, right)

	cout.Flush()
}

func good(arr []int, x, d int) (bool, int, int) {
	tarr := make([]int, len(arr))
	for i, num := range arr {
		tarr[i] = num - x
	}

	preff := make([]int, len(arr))
	preff[0] = arr[0] - x
	
	for i := 1; i != len(arr); i++ {
		preff[i] = preff[i - 1] + tarr[i]
	}



	// minPreffIdx := make([]int, len(arr))
	// minPreffIdx[0] = 0

	// for i := 1; i != len(arr); i++ {
	// 	if preff[i] < preff[minPreffIdx[i - 1]] {
	// 		minPreffIdx[i] = i
	// 	} else {
	// 		minPreffIdx[i] = minPreffIdx[i - 1]
	// 	}
	// }


	// for r := d - 1; r != len(arr); r++ {
	// 	l := r - d + 1
	// 	if preff[r] - preff[minPreffIdx[l]] >= 0 {
	// 		return true, l, r
	// 	}
	// }

	// return false, -1, -1
}

func bin(arr []int, d int) (int, int) {
	l := 0
	r := 1
	flag, _, _ := good(arr, r, d)
	for flag {
		r *= 2
		flag, _, _ = good(arr, r, d)
	}

	var left, right int
	for r != l + 1 {
		mid := (l + r) / 2
		if ok, tmpleft, tmpright := good(arr, mid, d); ok {
			l = mid
			left = tmpleft
			right = tmpright
		} else {
			r = mid
		}
	}

	return left, right
}