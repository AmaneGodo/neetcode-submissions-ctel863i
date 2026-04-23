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
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* root, int limit) {
        if (!root) {
            return 0;
        }

        if (root->val >= limit) {
            return dfs(root->left, root->val) + dfs(root->right, root->val) + 1;
        } else {
            return dfs(root->left, limit) + dfs(root->right, limit);
        }
    }    
};
