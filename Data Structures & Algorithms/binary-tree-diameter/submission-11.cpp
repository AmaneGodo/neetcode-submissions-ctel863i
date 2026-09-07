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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        dfs(root, dia);
        return dia;
    }

private:
    int dfs(TreeNode* root, int& d) {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left, d);
        int right = dfs(root->right, d);

        d = max(d, left + right);
        return max(left, right) + 1;
    }

};
