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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        queue<pair<TreeNode*, bool>> q;
        q.push({root, 0});
        TreeNode* temp;
        while (!q.empty()) {
            temp = q.front().first;
            if (q.front().second && !temp->left && !temp->right) sum += temp->val;
            if (temp->left) q.push({temp->left, 1});
            if (temp->right) q.push({temp->right, 0});
            q.pop();
        }
        return sum;
    }
};