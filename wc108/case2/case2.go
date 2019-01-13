package main

import (
	"fmt"
)

func findzero(A []int) int {
	// find continues zero
	// use to math to find all comb
	var count, start, end int
	var cont bool
	for i, v := range A {
		if v == 0 {
			if !cont {
				cont = true
				start = i
				end = i
			} else {
				end++
			}
		} else {
			cont = false
			count += (end - start + 1) * (end - start + 2) / 2
		}
	}
	if cont {
		count += (end - start + 1) * (end - start + 2) / 2
	}
	return count
}

func findsub(A []int, s int) int {
	// find subarray with max sum one
	var n = len(A)
	if n == 0 {
		return 0
	} else if n == 1 {
		if A[0] == s {
			return 1
		}
		return 0
	}
	var sum = A[0]
	var start, end = 0, 1
	var count int
	for start != n {
		switch end < n {
		case true:
			if sum == s {
				count++
				if A[end] == 0 {
					end++
				} else {
					sum -= A[start]
					start++
				}
			} else if sum < s {
				if end < n {
					sum += A[end]
					end++
				}
			} else {
				sum -= A[start]
				start++
			}
		default:
			if sum == s {
				count++
			}
			sum -= A[start]
			start++
		}
	}
	return count
}

func numSubarraysWithSum(A []int, S int) int {
	switch S {
	case 0:
		return findzero(A)
	default:
		return findsub(A, S)
	}
}

func main() {
	fmt.Println(numSubarraysWithSum([]int{0, 0, 0, 0, 0}, 0))
	fmt.Println(numSubarraysWithSum([]int{0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 0))
	fmt.Println(numSubarraysWithSum([]int{1, 0, 1, 0, 1}, 2))
	fmt.Println(numSubarraysWithSum([]int{1, 0, 0, 0, 0}, 1))
	fmt.Println(numSubarraysWithSum([]int{1, 1, 1, 1, 1}, 5))
}
