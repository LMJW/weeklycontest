package main

import (
	"fmt"
)

func inorder(w1, w2 string, dict map[byte]int) bool {
	var l1 = len(w1)
	var l2 = len(w2)
	var ll int

	if l1 > l2 {
		ll = l2
	} else {
		ll = l1
	}

	for i := 0; i < ll; i++ {
		if dict[w1[i]] < dict[w2[i]] {
			return true
		} else if dict[w1[i]] > dict[w2[i]] {
			return false
		}
	}
	if l1 <= l2 {
		return true
	}
	return false
}

func isAlienSorted(words []string, order string) bool {
	var dict = map[byte]int{}
	for i, v := range order {
		dict[byte(v)] = i
	}

	var l = len(words)
	if l < 2 {
		return true
	}
	for i := 1; i < l; i++ {
		if !inorder(words[i-1], words[i], dict) {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isAlienSorted([]string{"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz"))
	fmt.Println(isAlienSorted([]string{"word", "world", "row"}, "worldabcefghijkmnpqstuvxyz"))
	fmt.Println(isAlienSorted([]string{"apple", "app"}, "abcdefghijklmnopqrstuvwxyz"))
}
