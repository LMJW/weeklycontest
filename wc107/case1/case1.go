package main

import (
	"fmt"
)

func isLongPressedName(name string, typed string) bool {
	var i, j int
	var n = len(name)
	var m = len(typed)
	if n > m {
		return false
	}
	var last byte
	for i < n && j < m {
		// fmt.Println(name[i], typed[j])
		if name[i] == typed[j] {
			last = name[i]
			j++
			i++
		} else if typed[j] == last {
			j++
		} else {
			return false
		}
	}
	// fmt.Println(i, j, n, m)

	if i == n && j == m {
		return true
	} else if i == n {
		for j < m {
			// fmt.Println(typed[j], name[i-1])
			if typed[j] != name[i-1] {
				return false
			}
			j++
		}
	}
	if i == n && j == m {
		return true
	}
	return false
}

func main() {
	fmt.Println(isLongPressedName("alex", "aaleex"))
	fmt.Println(isLongPressedName("saeed", "ssaaedd"))
	fmt.Println(isLongPressedName("leelee", "lleeelee"))
	fmt.Println(isLongPressedName("laiden", "laiden"))
	fmt.Println(isLongPressedName("vtkgn", "vttkgnn"))
}
