package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var cin = bufio.NewReader(os.Stdin)
var cout = bufio.NewWriter(os.Stdout)

func main() {
	var n, k int
	fmt.Fscan(cin, &n, &k)
	arr := make([]int, n)
	for i := range arr {
		fmt.Fscan(cin, &arr[i])
	}


	cout.Flush()
}

type hint struct {
	rstack, lstack stack
}

func (hf *hint) add(x int) {
	hf.rstack.add(x)
}

func (hf *hint) remove() {
	if hf.lstack.len() == 0 {
		for hf.rstack.len() != 0 {
			hf.lstack.add(hf.rstack.remove())
		}
	}

	hf.lstack.remove()
}

type stack struct {
	data []int
	dmin []int
	dmax []int
}

func (st *stack) len() int {
	return len(st.data)
}

func (st *stack) add(x int) {
	st.data = append(st.data, x)

	if len(st.dmax) != 0 {
		st.dmax = append(st.dmax, int(math.Max(float64(x), float64(st.dmax[len(st.dmax) - 1]))))
	} else {
		st.dmax = append(st.dmax, x)
	}
	
	if len(st.dmin) != 0 {
		st.dmin = append(st.dmin, int(math.Min(float64(x), float64(st.dmin[len(st.dmin) - 1]))))
	} else {
		st.dmin = append(st.dmin, x)
	}
}

func (st *stack) remove() int {
	del := st.data[len(st.data) - 1]
	st.data = st.data[:len(st.data) - 1]
	st.dmax = st.dmax[:len(st.dmax) - 1]
	st.dmin = st.dmin[:len(st.dmin) - 1]
	return del
}
