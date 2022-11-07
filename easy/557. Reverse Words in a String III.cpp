class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word;
        istringstream ss(s);
        while (ss >> word) {
            reverse(word.begin(), word.end());
            ans += word + " ";
        }
        ans.resize(ans.size() - 1);
        return ans;
    }
};