# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        q = deque()
        q.append(root)

        while q:
            qLen = len(q)
            level = []

            for i in range(qLen):
                current_node = q.popleft()
                if current_node:
                    level.append(current_node.val)
                    q.append(current_node.left)
                    q.append(current_node.right)

            if level:
                res.append(level)

        return res