package main

import (
	"bufio"
	"fmt"
	"os"
)

var cin = bufio.NewReader(os.Stdin)
var cout = bufio.NewWriter(os.Stdout)

func main() {

	var n, p int
	fmt.Fscan(cin, &n, &p)
	arr := make([]int, n)
	sum := 0
	for i := range arr {
		fmt.Fscan(cin, &arr[i])
		sum += arr[i]
	}
	
	minln := (p / sum + 2) * n
	var left int
	var intBeforeR int
	
	hf := hint{}
	if sum < p {
		intBeforeR = (p / sum) + 1
		hf.sum = intBeforeR * sum

		for hf.sum - arr[hf.l] > p {
			hf.remove(arr[hf.l])
		}

		minln = (hf.r + intBeforeR * n) - hf.l
		left = hf.l
	} else {
		arr = append(arr, arr...)
	}

	for _, num := range arr {
		hf.add(num)
		for hf.sum - arr[hf.l] >= p {
			hf.remove(arr[hf.l])
		}

		if hf.sum >= p && getLen(intBeforeR, n, hf.r, hf.l) < minln {
			minln = getLen(intBeforeR, n, hf.r, hf.l)
			left = hf.l
		}
	}


	fmt.Fprintln(cout, left + 1, minln)

	cout.Flush()
}

type hint struct {
	l, r int
	sum int
}

func (hf *hint) add(x int) {
	hf.r++
	hf.sum += x
}

func (hf *hint) remove(x int) {
	hf.l++
	hf.sum -= x
}

func getLen(beforR, numInInt, r, l int) int {
	return (r + beforR * numInInt) - l
}