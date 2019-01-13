package main

import (
	"fmt"
)

func minFlipsMonoIncr(S string) int {
	var cz, co int
	var i, j = 0, len(S) - 1
	for i < j {
		if S[i] == '0' {
			i++
		} else if S[j] == '1' {
			j--
		} else {
			break
		}
	}
	var ss = S[i : j+1]
	var left, right = 0, len(ss) - 1
	for left < right {
		if ss[left] == '1' {
			left++
		}
	}

}

func main() {
	fmt.Println(minFlipsMonoIncr("00110"))
	fmt.Println(minFlipsMonoIncr("010110"))
	fmt.Println(minFlipsMonoIncr("00011000"))
	fmt.Println(minFlipsMonoIncr("0101100011"))
	fmt.Println(minFlipsMonoIncr("10011111110010111011"))
	fmt.Println(minFlipsMonoIncr("11111"))
}
