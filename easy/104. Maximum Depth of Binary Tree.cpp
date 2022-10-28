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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        root->val = 1;
        int max = 1;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            if (s.top()->left == NULL) {
                if (s.top()->val > max) max = s.top()->val;
                if (s.top()->right != NULL) {
                    s.top()->right->val = s.top()->val+1;
                    TreeNode* temp = s.top()->right;
                    s.pop();
                    s.push(temp);
                }
                else {
                    s.pop();
                }
            }
            else {
                s.top()->left->val = s.top()->val+1;
                TreeNode* temp = s.top()->left;
                s.top()->left = NULL;
                s.push(temp);
            }
        }
        return max;
    }
};