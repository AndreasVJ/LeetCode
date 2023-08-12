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
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left, root->right, true);
        return root;
    }
    void helper(TreeNode* l, TreeNode* r, bool reverse) {
        if (!l) return;
        if (reverse) swap(l->val, r->val);
        helper(l->left, r->right, !reverse);
        helper(l->right, r->left, !reverse);
        return;
    }
};