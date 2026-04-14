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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);

        while (!q.empty()) {
            int qLen = q.size();
            vector<int> level;

            for (int i = 0; i < qLen; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur) {
                    q.push(cur->left);
                    q.push(cur->right);
                    level.push_back(cur->val);
                }
            
            }

            if (!level.empty()) {
                res.push_back(level);
            }
        }

        return res;
    }
};
