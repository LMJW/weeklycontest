class Solution:
    def smallestFromLeaf(self, root: "TreeNode") -> "str":
        self.res = "z" * 1000

        def dfs(root, cur):
            cur = d[root.val] + cur
            if root.left == None and root.right == None:
                if cur < self.res:
                    self.res = cur
            if root.left != None:
                dfs(root.left, cur)
            if root.right != None:
                dfs(root.right, cur)

        d = {i: chr(ord("a") + i) for i in range(26)}

        dfs(root, "")
        return self.res

