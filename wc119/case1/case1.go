package main

import (
	"fmt"
	"sort"
)

type pp struct {
	cord []int
	dist int
}

func kClosest(points [][]int, K int) [][]int {
	var plist []pp

	for _, p := range points {
		plist = append(plist, pp{
			cord: p,
			dist: p[0]*p[0] + p[1]*p[1],
		})
	}

	sort.SliceStable(plist, func(i, j int) bool {
		return plist[i].dist < plist[j].dist
	})

	var res [][]int
	for i := 0; i < K; i++ {
		res = append(res, plist[i].cord)
	}
	return res
}
func main() {
	fmt.Println(kClosest([][]int{[]int{1, 3}, []int{-2, 2}}, 1))
}
