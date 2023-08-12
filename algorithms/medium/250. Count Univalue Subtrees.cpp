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
    pair<int, bool> helper(TreeNode* root) {

        if (!root) return {0, 0};
        if (!root->left && !root->right) return {1, 1};
        
        pair<int, bool> left = helper(root->left);
        pair<int, bool> right = helper(root->right);

        int ans = left.first + right.first;

        if (left.second && right.second) {
            if (root->left->val == root->val && root->right->val == root->val) return {ans + 1, 1};
        }
        else if (left.second && !right.first && !right.second) {
            if (root->left->val == root->val) return {ans + 1, 1};
        }
        else if (!left.first && !left.second && right.second) {
            if (root->right->val == root->val) return {ans + 1, 1};
        }

        return {ans, 0};
    }


    int countUnivalSubtrees(TreeNode* root) {
        pair<int, bool> ans = helper(root);
        return ans.first;
    }
};