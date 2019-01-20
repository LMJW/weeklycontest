package main

import "sort"

func sortedSquares(A []int) []int {
	var res []int
	for i := range A {
		res = append(res, A[i]*A[i])
	}
	sort.Ints(res)
	return res
}

func main() {
}
