package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructmaxtix(root *TreeNode) (map[int]int, [][2]int, int) {
	var idx int

	var nodemap = map[*TreeNode]int{}
	var nodecoin = map[int]int{}
	var distance [][2]int
	var traver func(*TreeNode)

	// traver the tree to get the distance map
	traver = func(n *TreeNode) {
		if _, ok := nodemap[n]; !ok {
			nodemap[n] = idx
			idx++
			if n.Val > 0 {
				nodecoin[nodemap[n]] = n.Val
			}
		}
		if n.Left != nil {
			nodemap[n.Left] = idx
			idx++
			distance = append(distance, [2]int{nodemap[n], nodemap[n.Left]})
		}
		if n.Right != nil {
			nodemap[n.Right] = idx
			idx++
			distance = append(distance, [2]int{nodemap[n], nodemap[n.Right]})
		}

		if n.Left != nil {
			traver(n.Left)
		}
		if n.Right != nil {
			traver(n.Right)
		}
	}

	return nodecoin, distance, idx
}

func distributeCoins(root *TreeNode) int {
	coins, distances, nnodes := constructmaxtix(root)

	var matrix = [][]int{}

	for i := 0; i < nnodes; i++ {
		var row = make([]int, nnodes)
		matrix = append(matrix, row)
	}

	for i, v := range distances {
		var a, b = v[0], v[1]
		matrix[a][b] = 1
		matrix[b][a] = 1
	}

}

func main() {
}
