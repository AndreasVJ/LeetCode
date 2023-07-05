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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }

    TreeNode* helper(vector<int>& nums, int a, int b) {
        if (a >= b) return nullptr;
        TreeNode* root = new TreeNode();
        int maxIndex = a;
        for (int i = a+1; i < b; i++) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }
        root->val = nums[maxIndex];
        root->left = helper(nums, a, maxIndex);
        root->right = helper(nums, maxIndex+1, b);
        return root;
    }
};