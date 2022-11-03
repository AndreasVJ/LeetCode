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
        vector<vector<int>> ans = {{}};
        int level = 1;
        queue<TreeNode*> q;
        root->val += 1000;
        q.push(root);
        while (!q.empty()) {
            if ((q.front()->val)/(2001)+1 > level) {
                level++;
                ans.push_back({});
            }
            ans[level-1].push_back(q.front()->val%2001-1000);
            if (q.front()->left) {
                q.front()->left->val += 1000 + 2001*level;
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                q.front()->right->val += 1000 + 2001*level;
                q.push(q.front()->right);
            }
            q.pop();
        }
        return ans;
    }
};