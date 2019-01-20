package main

import "fmt"

type point struct {
	start int
	end   int
	val   int
}

func subarraysDivByK(A []int, K int) int {
	var count int
	var stack []point
	var matched []point
	for i := 0; i < len(A); i++ {
		l := len(stack)
		if A[i]%K == 0 {
			matched = append(matched, point{start: i, end: i})
		} else if l == 0 {
			stack = append(stack, point{start: i, end: i, val: A[i]})
		} else {
			for
		}
	}

	return count
}

func main() {
	fmt.Println(subarraysDivByK([]int{1, 2, 3, 4, 5, 6, 7, 8, 9}, 5))
	fmt.Println(subarraysDivByK([]int{4, 5, 0, -2, -3, 1}, 5))

}
