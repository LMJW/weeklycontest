package main

import (
	"fmt"
)

func power(a, b int) int {
	if b == 0 {
		return 1
	}
	for ; b > 1; b-- {
		a *= a
	}
	return a
}

func powerfulIntegers(x int, y int, bound int) []int {
	var al, bl []int
	var hash = map[int]bool{}
	var t int

	if x == 0 {
		al = []int{0, 1}
	} else if x == 1 {
		al = []int{1}
	} else {
		t = 1
		for {
			if t <= bound {
				al = append(al, t)
			} else {
				break
			}
			t *= x
			// fmt.Println(t)
		}
	}

	if y == 0 {
		bl = []int{0, 1}
	} else if y == 1 {
		bl = []int{1}
	} else {
		t = 1
		for {
			if t <= bound {
				bl = append(bl, t)
			} else {
				break
			}
			t *= y
			// fmt.Println(t)
		}
	}
	for i := 0; i < len(al); i++ {
	sec:
		for j := 0; j < len(bl); j++ {
			var v = al[i] + bl[j]
			if v <= bound {
				hash[v] = true
			} else {
				break sec
			}
		}
	}
	var res []int
	for k := range hash {
		res = append(res, k)
	}
	return res
}

func main() {
	// fmt.Println(powerfulIntegers(2, 3, 10))
	// fmt.Println(powerfulIntegers(3, 5, 15))
	fmt.Println(powerfulIntegers(1, 2, 100))
}
