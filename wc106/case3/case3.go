package main

import (
	"fmt"
	"sort"
)

func choose(n, a int) int {
	var res = 1
	for i := 0; i < a; i++ {
		res *= n - i
		res /= i + 1
	}
	return res
}

func threeSumMulti(A []int, target int) int {
	var res int
	var n = len(A)
	if n < 3 {
		return res
	}
	sort.Ints(A)
	for i := 0; i < n-2; i++ {
		var left = i + 1
		var right = n - 1
		for left < right {
			var sum = A[i] + A[left] + A[right]
			if sum == target {
				if A[left] == A[right] {
					res += choose(right-left+1, 2)
					left = right
				} else {
					var lc, rc = 1, 1
					for A[left] == A[left+1] {
						left++
						lc++
					}
					for A[right] == A[right-1] {
						right--
						rc++
					}
					res += lc * rc
					left++
					right--
				}
			} else if sum < target {
				for left+1 < right && A[left] == A[left+1] {
					left++
				}
				left++
			} else if sum > target {
				for left < right-1 && A[right] == A[right-1] {
					right--
				}
				right--
			}
		}
	}
	return res % (1e9 + 7)
}

func main() {
	fmt.Println(threeSumMulti([]int{3, 3, 2, 0, 2}, 7))
}
