# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.heads = []
        stack = [root]
        while stack:
            self.heads.extend(stack)
            children = []
            for node in stack:
                if node.left:
                    children.append(node.left)
                if node.right:
                    children.append(node.right)
            stack = children

    def insert(self, v):
        """
        :type v: int
        :rtype: int
        """
        l = len(self.heads)
        idx = (l-1)//2
        if self.heads[idx].left == None:
            self.heads[idx].left = Treenode(v)
        else:
            self.heads[idx].right = TreeNode(v)
        return self.heads[idx].val


    def get_root(self):
        """
        :rtype: TreeNode
        """
        return self.heads[0]


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()