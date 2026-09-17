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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::queue<TreeNode*> q;
        q.push(root);
        vector<int> res;

        while (!q.empty()) {
            int qlen = q.size();
            int right_num;

            for (int i = 0; i < qlen; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }

                if (i == (qlen - 1)) {
                    right_num = node->val;
                }
            }

            if (right_num) {
                res.push_back(right_num);
            }
        }

        return res;
    }
};
