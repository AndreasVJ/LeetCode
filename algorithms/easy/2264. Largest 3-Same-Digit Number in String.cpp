class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i <= num.size() - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                if (ans == "" or num[i] > ans[0]) ans = num.substr(i, 3);
            }
        }
        return ans;
    }
};