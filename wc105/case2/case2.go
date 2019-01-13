package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type CBTInserter struct {
	nodes []*TreeNode
}

func leveltraverse(root *TreeNode) []*TreeNode {
	var nodes []*TreeNode
	nodes = append(nodes, root)
	nodes = append
}

func Constructor(root *TreeNode) CBTInserter {

}

func (this *CBTInserter) Insert(v int) int {

}

func (this *CBTInserter) Get_root() *TreeNode {

}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Insert(v);
 * param_2 := obj.Get_root();
 */

func main() {}
