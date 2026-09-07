# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def isSameTree(main, sub):
            if not main and not sub:
                return True

            if main and sub and main.val == sub.val:
                return isSameTree(main.left, sub.left) and isSameTree(main.right, sub.right)

            else:
                return False

        if not root:
            return False

        if not subRoot:
            return True

        if isSameTree(root, subRoot):
            return True
            
        return self.isSubtree(root.right, subRoot) or self.isSubtree(root.left, subRoot)