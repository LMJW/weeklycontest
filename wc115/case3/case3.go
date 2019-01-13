package main

import "fmt"

func prisonAfterNDays(cells []int, N int) []int {
	var s string
	var states map[string]bool
	for _, v := range cells {
		if v == 0 {
			s += "0"
		} else {
			s += "1"
		}
	}

}

func main() {
	fmt.Println(prisonAfterNDays([]int{0, 1, 0, 1, 1, 0, 0, 1}, 1000000000))
}
