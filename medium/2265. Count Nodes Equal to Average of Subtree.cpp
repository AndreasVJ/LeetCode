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
    int averageOfSubtree(TreeNode* root) {
        return dfs(root)[2];
    }
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0, 0};
        vector<int> ans = dfs(root->left);
        vector<int> right = dfs(root->right);
        ans[0] += right[0] + root->val;
        ans[1] += right[1] + 1;
        ans[2] += right[2];
        if (root->val == ans[0]/ans[1]) ans[2]++;
        return ans;
    } 
};