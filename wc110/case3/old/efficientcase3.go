package main

import (
	"fmt"
	"sort"
)

func abs(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}

func setintersect(m1, m2 map[int]bool) int {
	var inter = map[int]bool{}
	for k := range m1 {
		if m2[k] {
			inter[k] = true
		}
	}
	if len(inter) < 2 {
		return 0
	}
	var l []int
	for k := range inter {
		l = append(l, k)
	}
	sort.Ints(l)
	var mindif = 1 << 62
	for i := 1; i < len(l); i++ {
		t := l[i] - l[i-1]
		if mindif > t {
			mindif = t
		}
	}
	return mindif
}

func minAreaRect(points [][]int) int {
	var m = map[int]map[int]bool{}

	var area = 1 << 62
	var keys []int
	for _, v := range points {
		if m[v[0]] == nil {
			t := map[int]bool{}
			t[v[1]] = true
			m[v[0]] = t
		} else {
			m[v[0]][v[1]] = true
		}
	}
	for k := range m {
		keys = append(keys, k)
	}
	for i := 0; i < len(keys); i++ {
		if len(m[keys[i]]) < 2 {
			continue
		}
		for j := i + 1; j < len(keys); j++ {
			t := setintersect(m[keys[i]], m[keys[j]])
			if t != 0 && area > abs(keys[i]-keys[j])*t {
				area = abs(keys[i]-keys[j]) * t
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
	fmt.Println(minAreaRect([][]int{[]int{0, 1}, []int{1, 3}, []int{3, 3}, []int{4, 4}, []int{1, 4}, []int{2, 3}, []int{1, 0}, []int{3, 4}}))
}

// [[0,1],[1,3],[3,3],[4,4],[1,4],[2,3],[1,0],[3,4]]
// [[3,2],[0,0],[3,3],[3,4],[4,4],[2,1],[4,3],[1,0],[4,1],[0,2]]
// [[0,1],[1,3],[3,3],[4,4],[1,4],[2,3],[1,0],[3,4]]
