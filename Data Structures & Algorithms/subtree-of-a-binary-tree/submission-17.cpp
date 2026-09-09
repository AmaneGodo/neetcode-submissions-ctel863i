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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        if (!subRoot) {
            return true;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* main, TreeNode* sub) {
        if (!main and !sub) {
            return true;
        }

        if (main && sub && main->val == sub->val) {
            return isSameTree(main->left, sub->left) && isSameTree(main->right, sub->right);
        } else {
            return false;
        }
    }
};
