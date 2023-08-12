class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int l = min(word1.size(), word2.size());
        for (int i = 0; i < l; i++) {
            ans += word1[i];
            ans += word2[i];
        }
        if (word1.size() > word2.size()) {
            ans += word1.substr(l, word1.size());
        }
        else {
            ans += word2.substr(l, word2.size());
        }
        return ans;
    }
};