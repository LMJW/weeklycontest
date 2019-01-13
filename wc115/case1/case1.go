package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isCompleteTree(root *TreeNode) bool {
	var stack []*TreeNode
	var ns []*TreeNode
	var foundnull bool

	stack = append(stack, root)

	for len(stack) > 0 {
		for _, v := range stack {
			fmt.Println(v)
			if v != nil {
				if foundnull == true {
					return false
				}
				if v.Left != nil {
					ns = append(ns, v.Left)
				} else {
					ns = append(ns, nil)
				}
				if v.Right != nil {
					ns = append(ns, v.Right)
				} else {
					ns = append(ns, nil)
				}
			} else {
				if foundnull == true {
					continue
				} else {
					foundnull = true
				}
			}
		}
		stack = ns
		ns = []*TreeNode{}
	}
	return true
}

func main() {
	n := &TreeNode{
		Val: 2,
		Left: &TreeNode{
			Val: 3,
		},
		Right: &TreeNode{
			Val: 4,
		},
	}
	fmt.Println(isCompleteTree(n))
}
