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
    bool isBalanced(TreeNode* root) {
        if (dfs(root)[1] == 1) {
            return true;
        } else {
            return false;
        }
    }

private:
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 1};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        int check;

        if ((left[1] == 1) && (right[1] == 1) && (abs(left[0] - right[0]) <= 1)) {
            check = 1;
        } else {
            check = 0;
        }

        return {max(left[0], right[0]) + 1, check};
    }
};
