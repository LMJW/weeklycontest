package main

import (
	"fmt"
)

func bagOfTokensScore(tokens []int, p int) int {
	var points int
	for _, t := range tokens {
		if p >= t {
			p -= t
			points++
		} else {
			if
		}
	}
	return points
}

func main() {
	fmt.Println(bagOfTokensScore([]int{100, 200, 300, 400}, 200))
	fmt.Println(bagOfTokensScore([]int{58, 91}, 50))
}
