package main

import (
	"fmt"
	"sort"
)

func isTrangle(x, y, z int) bool {
	return x+y > z
}

func totallen(x, y, z int) int {
	return x + y + z
}

func largestPerimeter(A []int) int {
	var l = len(A)
	var a, b, c int
	var found = false
	sort.Ints(A)
	for i := l - 1; i-2 >= 0; i-- {
		a, b, c = A[i-2], A[i-1], A[i]
		if isTrangle(a, b, c) {
			found = true
			break
		}
	}
	if found {
		return totallen(a, b, c)
	}
	return 0
}

func main() {
	fmt.Println(largestPerimeter([]int{2, 1, 2}))
	fmt.Println(largestPerimeter([]int{1, 2, 1}))
	fmt.Println(largestPerimeter([]int{3, 2, 3, 4}))
	fmt.Println(largestPerimeter([]int{3, 6, 2, 3}))
}
