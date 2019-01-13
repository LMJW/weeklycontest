package main

import "fmt"

func leastOpsExpressTarget(x int, target int) int {
	var val = []int{1}
	var ops = []int{1}
	for i, t := 1, x; t < target; i++ {
		t *= x
		val = append(val, t)
		ops = append(val, i)
	}

}

func main() {
	fmt.Println(leastOpsExpressTarget(3, 19))
	fmt.Println(leastOpsExpressTarget(5, 501))
	fmt.Println(leastOpsExpressTarget(100, 100000000))
}
