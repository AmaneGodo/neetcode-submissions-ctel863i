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
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);   
    }

private:
    bool dfs(TreeNode* root, int left_bound, int right_bound) {
        if (!root) {
            return true;
        }

        if (root->val > left_bound && root->val < right_bound) {
            return dfs(root->left, left_bound, root->val) && dfs(root->right, root->val, right_bound);
        } else {
            return false;
        }
    }

};
