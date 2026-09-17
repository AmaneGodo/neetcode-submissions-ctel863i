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
        // return dfs(root, -INT_MAX, INT_MAX);
        if (!root) {
            return true;
        }

        std::queue<tuple<TreeNode*, int, int>> q;
        q.push({root, -INT_MAX, INT_MAX});

        while (!q.empty()) {
            int qlen = q.size();

            for (int i = 0; i < qlen; i++) {
                auto [node, left, right] = q.front();
                q.pop();
                
                if (node->val <= left || node->val >= right) {
                    return false;
                }

                if (node->left != nullptr) {
                    q.push({node->left, left, node->val});
                }

                if (node->right != nullptr) {
                    q.push({node->right, node->val, right});
                }
            } 
        }

        return true;
    }

private:
    bool dfs(TreeNode* root, int left, int right) {
        if (!root) {
            return true;
        }

        if (root->val > left && root->val < right) {
            return dfs(root->right, root->val, right) and dfs(root->left, left, root->val);
        }

        else {
            return false;
        }
    }
};
