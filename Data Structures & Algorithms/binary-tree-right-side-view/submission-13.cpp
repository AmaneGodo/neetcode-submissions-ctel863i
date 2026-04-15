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
        std::queue<TreeNode*> q;
        std::vector<int> res;
        q.push(root);

        while (!q.empty()) {
            int qLen = q.size();
            int right = INT_MAX;

            for (int i = 0; i < qLen; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur) {
                    right = cur->val;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }

            if (right != INT_MAX) {
                res.push_back(right);
            }
        }

        return res;
    }
};
