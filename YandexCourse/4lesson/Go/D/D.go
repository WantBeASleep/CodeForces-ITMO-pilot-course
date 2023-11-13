package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type mod struct {
	m int
	name string
}

func main() {
	sc := bufio.NewScanner(os.Stdin)

	var total int
	condition := make(map[string]int)
	var order []string
	for (sc.Scan()) {
		if sc.Text() == "" {
			break
		}

		pos := strings.LastIndex(sc.Text(), " ")
		partyname := sc.Text()[:pos]
		votes, _ := strconv.Atoi(sc.Text()[pos + 1:])

		_, flag := condition[partyname]
		if !flag {
			order = append(order, partyname)
		}
		condition[partyname] += votes
		total += votes
	}

	firstConst := total / 450

	ans := make(map[string]int)
	modlist := make([]mod, len(order))

	var firstDistrub int
	var i int
	for _, s := range order {
		if firstConst != 0 {
			ans[s] = condition[s] / firstConst	
		} else {
			ans[s] = 0
		}
		firstDistrub += ans[s]

		modlist[i] = mod{condition[s] % firstConst, s}
		i++
	}

	if (firstDistrub != 450) {
		sort.Slice(modlist, func(i, j int) bool {
			if modlist[i].m == modlist[j].m {
				return condition[modlist[i].name] > condition[modlist[j].name]
			} else {
				return modlist[i].m > modlist[j].m
			}
		})

		var i int
		for firstDistrub != 450 {
			i %= len(modlist)
			ans[modlist[i].name]++
			firstDistrub++
			i++

		}
	}

	for _, s := range order {
		fmt.Println(s, ans[s])
	}
}