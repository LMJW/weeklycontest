package main

import "fmt"

func maxWidthRamp(A []int) int {
	var total = len(A)
	if total < 2 {
		return 0
	}
	var ans = 0
	for i := 0; i < total; i++ {
		for j := ans; i+j < total; j++ {
			if A[i] <= A[i+j] && j > ans {
				ans = j
			}
		}
	}
	return ans
}

func main() {
	fmt.Println(maxWidthRamp([]int{3, 1, 2}))
	// fmt.Println(maxWidthRamp([]int{6, 0, 8, 2, 1, 5}))
	// fmt.Println(maxWidthRamp([]int{6, 5, 4, 3, 2, 1, 0}))
	// fmt.Println(maxWidthRamp([]int{9, 8, 1, 0, 1, 9, 4, 0, 4, 1}))
}
