package main

import "fmt"

func subarraysDivByK(A []int, K int) int {
	var tmp = make([]int, len(A))
	var count int
	for i := 0; i < len(A); i++ {
		var t = A[i] % K
		if t == 0 {
			count++
		}
		tmp[i] = t

		for j := 0; j < i; j++ {
			tmp[j] += t
			tmp[j] %= K
			if tmp[j] == 0 {
				count++
			}
		}
	}
	return count
}

func main() {
	fmt.Println(subarraysDivByK([]int{1, 2, 3, 4, 5, 6, 7, 8, 9}, 5))
	fmt.Println(subarraysDivByK([]int{4, 5, 0, -2, -3, 1}, 5))

}
