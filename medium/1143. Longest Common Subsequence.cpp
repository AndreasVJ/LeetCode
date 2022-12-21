class Solution {
public:
    int helper(vector<vector<int>>& memo, string& t1, string& t2, int a, int b) {
         
        if (a == t1.size() || b == t2.size()) return 0;

        if (memo[a][b] != -1) {
            return memo[a][b];
        }
        
        int opt1 = helper(memo, t1, t2, a, b + 1);
        
        int i = a;
        while (i < t1.size() && t1[i] != t2[b]) i++;
        if (i == t1.size()) return opt1;  

        return memo[a][b] = max(opt1, 1 + helper(memo, t1, t2, i + 1, b + 1));
    }


    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));

        return helper(memo, text1, text2, 0, 0);
    }
};