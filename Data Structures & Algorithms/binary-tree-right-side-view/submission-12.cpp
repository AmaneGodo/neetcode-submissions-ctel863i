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
            int qLen = q.size();
            int right;

            for (int i = 0; i < qLen; i++) {
                TreeNode* cur = q.front();
                q.pop();

                right = cur->val;
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }

            res.push_back(right);
        }

        return res;
    }
};
