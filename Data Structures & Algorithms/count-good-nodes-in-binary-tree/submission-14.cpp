/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int maxVal) {
        if (!node) {
            return 0;
        }

        int res = 0;

        if (node->val >= maxVal) {
            res++;
        } 

        res += dfs(node->left, max(maxVal, node->val));
        res += dfs(node->right, max(maxVal, node->val));

        return res;
    }
};
