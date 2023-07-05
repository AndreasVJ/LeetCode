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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, 1, 1);
    }

    int dfs(TreeNode* root, int parent, int grandparent) {
        return root ? (dfs(root->left, root->val, parent) + dfs(root->right, root->val, parent) + (grandparent%2 ? 0 : root->val)) : 0;
    }
};