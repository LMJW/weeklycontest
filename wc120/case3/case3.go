package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}

func distributeCoins(root *TreeNode) int {
	var res int
	var calcost func(n *TreeNode) int

	calcost = func(n *TreeNode) int {
		var l, r int
		if n.Left != nil {
			l = calcost(n.Left)
		}
		if n.Right != nil {
			r = calcost(n.Right)
		}
		var t = n.Val + l + r - 1
		res += abs(t)
		return t
	}
	_ = calcost(root)

	return res
}

func main() {
}
