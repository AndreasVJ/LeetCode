class Solution {
public:
    vector<int> minOperations(string boxes) {
        int ops = 0;
        int right = 0;
        int left = 0;

        for (int i = 1; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                ops += i;
                right++;
            }
        }
        
        vector<int> ans = {ops};
        
        for (int i = 1; i < boxes.size(); i++) {
            ops -= right;
            if (boxes[i] == '1') right--;
            if (boxes[i - 1] == '1') left++;
            ops += left;
            ans.push_back(ops);
        }

        return ans;
    }
};