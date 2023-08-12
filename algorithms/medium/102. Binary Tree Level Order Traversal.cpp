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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        int level = 0;
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        while (!q.empty()) {
            int l = q.size();
            ans.push_back({});
            for (int i = 0; i < l; i++) {
                temp = q.front();
                q.pop();
                ans[level].push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            level++;
        }
        return ans;
    }
};