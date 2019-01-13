package main

import (
	"fmt"
)

func inorder(w1, w2 string, d map[int]bool) (bool, int) {
	var ll = len(w1)

	for i := 0; i < ll; i++ {
		if d[i] {
			continue
		}
		if w1[i] < w2[i] {
			return true, 0
		} else if w1[i] > w2[i] {
			return false, i
		}
	}
	return true, 0
}

func minDeletionSize(A []string) int {
	var delidx = map[int]bool{}
	var done bool
	var l = len(A)
	if l < 2 {
		return 0
	}

mainloop:
	for {
	secloop:
		for i := 1; i < l; i++ {
			order, idx := inorder(A[i-1], A[i], delidx)
			if !order {
				delidx[idx] = true
				break secloop
			}
			if i == l-1 && order {
				done = true
			}
		}
		if done {
			break mainloop
		}
	}
	// fmt.Println(delidx)
	return len(delidx)
}

func main() {
	fmt.Println(minDeletionSize([]string{"ca", "bb", "ac"}))
	fmt.Println(minDeletionSize([]string{"xc", "yb", "za"}))
	fmt.Println(minDeletionSize([]string{"zyx", "wvu", "tsr"}))
}
