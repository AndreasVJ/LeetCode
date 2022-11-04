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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        int n = 0;
        TreeNode* temp;
        while (!s.empty()) {
            temp = s.top();
            if (temp->left) s.push(temp->left);
            else {
                s.pop();
                if (temp->right) {
                    s.push(temp->right);
                }
                n++;
                if (n == k) return temp->val;
            }
            temp->left = nullptr;
        }
        return -1;
    }
};