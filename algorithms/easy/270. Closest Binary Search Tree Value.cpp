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
    int closestValue(TreeNode* root, double target) {

        int closest = root->val;

        while (root->left || root->right) {
            if (target > root->val) {
                if (root->right) root = root->right;
                else return closest;
            }
            else if (root->left) root = root->left;
            else return closest;

            if (abs(root->val - target) < abs(closest - target)) closest = root->val;
        }
        return closest;
    }
};