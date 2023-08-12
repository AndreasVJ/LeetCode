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
    vector<TreeNode*> helper(int start, int end) {
        
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> trees;

        for (int i = start; i <= end; i++) {

            vector<TreeNode*> left = helper(start, i - 1);
            vector<TreeNode*> right = helper(i + 1, end);

            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    trees.push_back(curr);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }
};