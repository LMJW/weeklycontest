package main

import (
	"fmt"
	"sort"
)

// func canReorderDoubled(A []int) bool {
// 	var pos []int
// 	var neg []int
// 	var rep = map[int]int{}
// 	for _, v := range A {
// 		if v > 0 {
// 			if _, ok := rep[v]; !ok {
// 				pos = append(pos, v)
// 			}
// 		} else if v < 0 {
// 			if _, ok := rep[v]; !ok {
// 				neg = append(neg, -v)
// 			}
// 		}
// 		rep[v]++
// 	}
// 	if len(pos)%2 == 1 {
// 		return false
// 	}
// 	sort.Ints(pos)
// 	sort.Ints(neg)
// 	// fmt.Println(pos, neg, rep)
// 	for i := 0; i < len(pos)/2; i++ {
// 		if 2*pos[2*i] != pos[2*i+1] {
// 			return false
// 		}
// 		if rep[pos[2*i]] != rep[pos[2*i+1]] {
// 			return false
// 		}
// 	}
// 	for i := 0; i < len(neg)/2; i++ {
// 		if 2*neg[2*i] != neg[2*i+1] {
// 			// fmt.Println(neg[2*i], neg[2*i+1])
// 			return false
// 		}
// 		if rep[-neg[2*i]] != rep[-neg[2*i+1]] {
// 			return false
// 		}
// 	}
// 	if rep[0]%2 == 1 {
// 		return false
// 	}
// 	return true
// }

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func canReorderDoubled(A []int) bool {
	var cc = map[int]int{}
	var keys []int
	for _, v := range A {
		if _, ok := cc[v]; !ok {
			keys = append(keys, v)
		}
		cc[v]++
	}

	sort.Ints(keys)
	for _, v := range keys {
		if v%2 == 0 && cc[v] != 0 && cc[v/2] != 0 {
			m := min(cc[v], cc[v/2])
			cc[v] -= m
			cc[v/2] -= m
		} else if cc[v] != 0 && cc[2*v] != 0 {
			m := min(cc[v], cc[v*2])
			cc[v] -= m
			cc[2*v] -= m
		}
	}
	// fmt.Println(keys, cc)
	for i, v := range cc {
		if i != 0 && v != 0 {
			return false
		} else if i == 0 && cc[i]%2 == 1 {
			return false
		}
	}

	return true
}

func main() {
	fmt.Println(canReorderDoubled([]int{3, 1, 3, 6}))
	fmt.Println(canReorderDoubled([]int{2, 1, 2, 6}))
	fmt.Println(canReorderDoubled([]int{4, -2, 2, -4}))
	fmt.Println(canReorderDoubled([]int{1, 2, 4, 16, 8, 4}))
	fmt.Println(canReorderDoubled([]int{2, 1, 2, 1, 1, 1, 2, 2}))
	fmt.Println(canReorderDoubled([]int{-8, -4, -2, -1, 0, 0, 1, 2, 4, 8}))
	fmt.Println(canReorderDoubled([]int{-2, -6, -3, 4, -4, 2}))
	fmt.Println(canReorderDoubled([]int{1, 2, 1, -8, 8, -4, 4, -4, 2, -2}))
	fmt.Println(canReorderDoubled([]int{-1, 4, 6, 8, -4, 6, -6, 3, -2, 3, -3, -8}))
	fmt.Println(canReorderDoubled([]int{0, 0}))

}
