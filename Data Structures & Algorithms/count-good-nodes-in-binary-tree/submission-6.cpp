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
    int dfs(TreeNode* root, int max_val) {
        if (!root) {
            return 0;
        }

        int res;

        if (root->val >= max_val) {
            max_val = root->val;
            res = dfs(root->left, max_val) + dfs(root->right, max_val);
            return res + 1;
        } else {
            res = dfs(root->left, max_val) + dfs(root->right, max_val);
            return res;
        }
    }
};
