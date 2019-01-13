package main

import (
	"fmt"
)

func validMountainArray(A []int) bool {
	var n = len(A)
	if n < 3 {
		return false
	}
	var diff = []int{}
	for i := 1; i < n; i++ {
		var t int
		if A[i] > A[i-1] {
			t = 1
		} else if A[i] < A[i-1] {
			t = -1
		}
		diff = append(diff, t)
	}
	var count int
	if diff[0] != 1 {
		return false
	}
	for i := 1; i < n-1; i++ {
		if diff[i] == 0 {
			return false
		}
		if diff[i] != diff[i-1] {
			count++
		}
	}
	if count == 1 {
		return true
	}
	return false
}

func main() {
	fmt.Println(validMountainArray([]int{1, 2, 3, 4, 5}))
	fmt.Println(validMountainArray([]int{1, 2, 3, 4, 5, 4}))
	fmt.Println(validMountainArray([]int{1, 2, 3, 4, 5, 4, 3}))
	fmt.Println(validMountainArray([]int{3, 2, 1}))
	fmt.Println(validMountainArray([]int{3, 2, 3}))
	fmt.Println(validMountainArray([]int{1, 2, 3, 2, 3}))
	fmt.Println(validMountainArray([]int{3, 5, 5}))

}
