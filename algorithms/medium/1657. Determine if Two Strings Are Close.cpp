class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> w1c(26, 0);
        vector<int> w2c(26, 0);
        
        for (char c : word1) w1c[c-'a']++;
        for (char c : word2) w2c[c-'a']++;

        for (int i = 0; i < 26; i++) {
            if (bool(w1c[i]) + bool(w2c[i]) == 1) return false;
        }

        sort(w1c.begin(), w1c.end());
        sort(w2c.begin(), w2c.end());

        return w1c == w2c;
    }
};