package main

import (
	"fmt"
	"strings"
)

func strWithout3a3b(a int, b int) string {
	var res []string
	var nextterm = a > b // true for a, false for b

	for a > 0 || b > 0 {
		if nextterm {
			if a > b && a >= 2 {
				res = append(res, "aa")
				a -= 2
			} else {
				res = append(res, "a")
				a--
			}
		} else {
			if b > a && b >= 2 {
				res = append(res, "bb")
				b -= 2
			} else {
				res = append(res, "b")
				b--
			}
		}
		nextterm = !nextterm
		// fmt.Println(a, b)
	}

	return strings.Join(res, "")
}

func main() {
	fmt.Println(strWithout3a3b(1, 2))
	fmt.Println(strWithout3a3b(4, 1))
	fmt.Println(strWithout3a3b(2, 5))
}
