package main

import (
	"fmt"
	"sort"
)

func minIncrementForUnique(A []int) int {
	var move int
	var dict = map[int]bool{}
	var movehist = map[int]int{}
	var dpmove = []int{}
	var dup = []int{}
	for _, i := range A {
		if dict[i] {
			dup = append(dup, i)
		} else {
			dict[i] = true
		}
	}
	sort.Ints(dup)
	for _, v := range dup {
		var freshmv int
		if ele, ok := movehist[v]; ok {
			freshmv = ele
		} else {
			if tt := len(dpmove); tt != 0 {
				last := dpmove[tt-1]
				lastdst := last + movehist[last]
				if v >= lastdst {
					freshmv = 0
				} else {
					freshmv = movehist[last] - v + last
				}
			}
		}
		// fmt.Println(v, freshmv, "---")

		var startv = v
		v += freshmv
		for dict[v] {
			v++
			freshmv++
		}
		dict[v] = true
		movehist[startv] = freshmv
		dpmove = append(dpmove, startv)
		move += freshmv
		// fmt.Println(move, movehist)
	}
	// fmt.Println(move, dict, movehist, dup)

	return move
}

func main() {
	fmt.Println(minIncrementForUnique([]int{1, 2, 2}))
	fmt.Println(minIncrementForUnique([]int{3, 2, 1, 2, 1, 7}))
	fmt.Println(minIncrementForUnique([]int{2, 2, 2, 1}))
	fmt.Println(minIncrementForUnique([]int{1, 1, 1}))
	fmt.Println(minIncrementForUnique([]int{13, 11, 4, 6, 4, 0, 0, 5, 3, 7, 2, 3, 10, 11, 4}))
}
