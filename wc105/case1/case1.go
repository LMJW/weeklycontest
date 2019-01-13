package main

func compare(x, y int) bool {
	if x >= 0 && y >= 0 {
		return true
	} else if x <= 0 && y <= 0 {
		return true
	} else {
		return false
	}
}

func maxSubarraySumCircular(A []int) int {
	var l = len(A)
	if l == 1 {
		return A[0]
	}
	var newa = []int{}
	var cur int
	for i := 0; i < l; {
		if compare(A[i], A[i+1]) {
			cur = A[i] + A[i+1]
		}
	}
}

func main() {}
