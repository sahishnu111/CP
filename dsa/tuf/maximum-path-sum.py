# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root):
        #your code goes here
        pathSUM=float('-inf')  # Initialize to negative infinity to handle negative values in the tree

        def dfs(node):
            if not node:
                return 0
            
            left = max(dfs(node.left), 0)  # Ignore negative paths
            right = max(dfs(node.right), 0)  # Ignore negative paths
            nonlocal pathSUM
            pathSUM = max(pathSUM, node.val + left + right)  # Update global max path sum
            return node.val + max(left, right)  # Return max path sum including current node
        dfs(root)
        return pathSUM

