class Node(object):
    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None


def pathtoNode(root, v):
    if root.info == v:
        return [root.info]
    else:
        if v < root.info:
            res = pathtoNode(root.left, v)
            res.append(root.info)
            return res
        else:
            res = pathtoNode(root.right, v)
            res.append(root.info)
            return res

root = Node(10)
root.left = Node(5)
root.left.left=Node(3)
root.left.left.right=Node(4)

print(pathtoNode(root, 4))