package main

import (
	"fmt"
	"sort"
)

func minIncrementForUnique(A []int) int {
	var move int
	var dict = map[int]bool{}
	var dup = []int{}
	var newa = []int{}
	for _, i := range A {
		if dict[i] {
			dup = append(dup, i)
		} else {
			dict[i] = true
			newa = append(newa, i)
		}
	}
	sort.Ints(newa)
	sort.Ints(dup)
	var dis = []int{0}
	for i := 1; i < len(newa); i++ {
		dis = append(dis, newa[i]-newa[i-1]-1+dis[i-1])
	}
	// fmt.Println(dis)
	var idx int
	for _, v := range dup {
		for i := idx; i < len(newa); i++ {
			if v == newa[i] {

			}
		}
	}

	// for _, v := range dup {
	// 	var freshmv int
	// 	if ele, ok := movehist[v]; ok {
	// 		freshmv = ele
	// 	}
	// 	var startv = v
	// 	v += freshmv
	// 	for dict[v] {
	// 		v++
	// 		freshmv++
	// 	}
	// 	dict[v] = true
	// 	movehist[startv] = freshmv
	// 	// fmt.Println(movehist)
	// 	move += freshmv
	// }
	// fmt.Println(move, dict, movehist, dup)

	return move
}

func main() {
	fmt.Println(minIncrementForUnique([]int{1, 2, 2}))
	fmt.Println(minIncrementForUnique([]int{3, 2, 1, 2, 1, 7}))
	fmt.Println(minIncrementForUnique([]int{2, 2, 2, 1}))
	fmt.Println(minIncrementForUnique([]int{1, 1, 1}))
	fmt.Println(minIncrementForUnique([]int{1, 4, 1, 2, 3}))
}
