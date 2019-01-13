package main

import (
	"fmt"
)

func abs(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}
func maxandmin(x []int) (int, int) {
	var max, min = 0, 1 << 62
	for _, v := range x {
		if v > max {
			max = v
		}
		if v < min {
			min = v
		}
	}
	return max, min
}

func bothin(arr []int, x, y int) bool {
	var xin, yin bool
	for _, v := range arr {
		if v == x {
			xin = true
		}
		if v == y {
			yin = true
		}
	}
	return xin && yin
}

func getpairs(arr []int) [][]int {
	var n = len(arr)
	var res [][]int
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			res = append(res, []int{arr[i], arr[j]})
		}
	}
	return res
}

func minAreaRect(points [][]int) int {
	var m = map[int][]int{}
	var area = 1 << 62
	var keys []int
	for _, v := range points {
		m[v[0]] = append(m[v[0]], v[1])
	}
	for k := range m {
		keys = append(keys, k)
	}
	for i := 0; i < len(keys); i++ {
		max, min := maxandmin(m[keys[i]])
		if max == min {
			continue
		}
		comb := getpairs(m[keys[i]])
		for _, c := range comb {
			c0, c1 := c[0], c[1]
			for j := i + 1; j < len(keys); j++ {
				if bothin(m[keys[j]], c0, c1) {
					t := abs((keys[i] - keys[j]) * (c0 - c1))
					if area > t {
						area = t
					}
				}
			}
		}
	}
	if area == 1<<62 {
		return 0
	}
	return area
}

func main() {
	fmt.Println(minAreaRect([][]int{[]int{1, 1}, []int{1, 3}, []int{3, 1}, []int{3, 3}, []int{4, 1}, []int{4, 3}}))
}

//[[0,1],[1,3],[3,3],[4,4],[1,4],[2,3],[1,0],[3,4]]
//[[3,2],[0,0],[3,3],[3,4],[4,4],[2,1],[4,3],[1,0],[4,1],[0,2]]
//[[0,1],[1,3],[3,3],[4,4],[1,4],[2,3],[1,0],[3,4]]
