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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root->val);
        dfs(root, path, ans);
        return ans;
    }

    void dfs(TreeNode* root, string& path, vector<string>& ans) {
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }
        if (root->left) {
            path += "->" + to_string(root->left->val);
            dfs(root->left, path, ans);
            while (path.back() != '>') path.pop_back();
            path.pop_back();
            path.pop_back();
        }
        if (root->right) {
            path += "->" + to_string(root->right->val);
            dfs(root->right, path, ans);
            while (path.back() != '>') path.pop_back();
            path.pop_back();
            path.pop_back();
        }
    }
};