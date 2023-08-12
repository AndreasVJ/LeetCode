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
    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        if (!root->left || !root->right) return 0;
        if (root->left->val != root->right->val) return 0;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        TreeNode* a;
        TreeNode* b;
        while (!q.empty()) {
            a = q.front().first;
            b = q.front().second;
            if (a->left) {
                if (!b->right) return 0;
                if (a->left->val != b->right->val) return 0;
                q.push({a->left, b->right});
            }
            else if (b->right) return 0;
            if (a->right) {
                if (!b->left) return 0;
                if (a->right->val != b->left->val) return 0;
                q.push({a->right, b->left});
            }
            else if (b->left) return 0;
            q.pop();
        }
        return 1;
    }
};