package main

import (
	"fmt"
)

func isinbasket(arr []int, x int) bool {
	for _, v := range arr {
		if x == v {
			return true
		}
	}
	return false
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func totalFruit(tree []int) int {
	var maxlen int
	var basket []int
	var curlen int
	for i, f := range tree {
		switch len(basket) {
		case 2:
			if isinbasket(basket, f) {
				if basket[0] == f {
					basket = append(basket[:1], f)
				}
				curlen++
				maxlen = max(maxlen, curlen)
			} else {
				maxlen = max(maxlen, curlen)
				basket = append(basket[1:], f)
				curlen = 2
			secondloop:
				for j := i - 2; j >= 0; j-- {
					if isinbasket(basket, tree[j]) {
						curlen++
					} else {
						break secondloop
					}
				}
			}
		default:
			if isinbasket(basket, f) {
				curlen++
			} else {
				curlen++
				basket = append(basket, f)
			}

		}
		maxlen = max(maxlen, curlen)
		fmt.Println(basket, curlen, maxlen, f)

	}
	return maxlen
}

func main() {
	fmt.Println(totalFruit([]int{1, 1, 6, 5, 6, 6, 1, 1, 1, 1}))
}
