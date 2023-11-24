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
    unordered_map<int, int> valCount;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans = {};
        int maxCount = 0;
        for (auto &[val, count] : valCount) {
            if (count > maxCount) {
                maxCount = count;
                ans = {val};
            }
            else if (count == maxCount) ans.push_back(val);
        }
        return ans;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int sum = dfs(root->left) + dfs(root->right) + root->val;
        valCount[sum]++;
        return sum;
    }
};