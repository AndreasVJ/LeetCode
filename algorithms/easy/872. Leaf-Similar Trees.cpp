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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return (leafValues(root1) == leafValues(root2));
    }

    vector<int> leafValues(TreeNode* root) {
        if (!root->left && !root->right) return {root->val};
        vector<int> a;
        vector<int> b;
        if (root->left) {
            a = leafValues(root->left);
        }
        if (root->right) {
            b = leafValues(root->right);
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};