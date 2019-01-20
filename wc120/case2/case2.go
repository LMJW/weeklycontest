package main

import "fmt"

func compare(a, b int) int {
	if a > b {
		return 1
	} else if a < b {
		return -1
	}
	return 0
}

func maxTurbulenceSize(A []int) int {
	var max int
	var lastcompare int
	var con = 1
	for i := 1; i < len(A); i++ {
		var t = compare(A[i-1], A[i])
		if t != 0 && t == -lastcompare {
			con++
		} else {
			con = 1
		}
		if con > max {
			max = con
		}
		lastcompare = t
	}
	return max + 1
}

func main() {
	fmt.Println(maxTurbulenceSize([]int{9, 4, 2, 10, 7, 8, 8, 1, 9}))
	fmt.Println(maxTurbulenceSize([]int{4, 8, 12, 16}))
	fmt.Println(maxTurbulenceSize([]int{100}))

}
