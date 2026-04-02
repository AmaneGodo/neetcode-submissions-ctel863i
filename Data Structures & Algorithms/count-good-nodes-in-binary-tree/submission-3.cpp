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
    int dfs(TreeNode* root, int maxVal) {
        if (!root) {
            return 0;
        }

        int res = (maxVal <= root->val) ? 1 : 0;
        maxVal = max(root->val, maxVal);
        res += dfs(root->left, maxVal);
        res += dfs(root->right, maxVal);

        return res;
    }

};
