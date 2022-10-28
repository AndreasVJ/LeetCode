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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            if (s.top()->left == NULL) {
                ans.push_back(s.top()->val);
                if (s.top()->right != NULL) {
                    TreeNode* temp = s.top()->right;
                    s.pop();
                    s.push(temp);
                }
                else s.pop();
            }
            else {
                TreeNode* temp = s.top()->left;
                s.top()->left = NULL;
                s.push(temp);
            }
        }
        return ans;
    }
};