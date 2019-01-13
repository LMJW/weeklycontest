# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        total = 0

        def findtotal(root):
            if root == None:
                return
            elif root.val <= R or root.val >= L:
                total += root.val
            findtotal(root.left)
            findtotal(root.right)
        return findtotal(root)
