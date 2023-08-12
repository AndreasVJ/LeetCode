class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        int i = 0;
        for (char c : pattern) {
            string word = "";
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            i++;
            if (m.contains(c)) {
                if (m[c] != word) return false;
            }
            else {
                for (auto const& [key, value] : m) {
                    if (value == word) return false;
                }
                m[c] = word;
            }
        }
        return i == s.size() + 1;
    }
};