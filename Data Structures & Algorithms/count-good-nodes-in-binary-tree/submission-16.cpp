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
        if (!root) {
            return 0;
        }

        std::queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        int res = 0;

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int maxVal = q.front().second;
            q.pop();

            if (node->val >= maxVal) {
                res++;
            }

            maxVal = max(node->val, maxVal);
            if (node->left != nullptr) {
                q.push({node->left, maxVal});
            }

            if (node->right != nullptr) {
                q.push({node->right, maxVal});
            }
        }

        return res;
    }
};
