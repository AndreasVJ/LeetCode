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
    vector<TreeNode*> ans;
    unordered_map<string, int> m;

    string helper(TreeNode* root) {
        
        if (!root) return "()";

        string key = "(" + helper(root->left) + to_string(root->val) + helper(root->right) + ")";

        if (m.find(key) != m.end()) {
            if (m[key] == 1) ans.push_back(root);
        }

        m[key]++;

        return key;
    }


    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return ans;
    }
};