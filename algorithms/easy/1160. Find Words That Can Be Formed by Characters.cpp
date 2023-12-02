class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charMap;
        for (char c : chars) {
            charMap[c]++;
        }
        int ans = 0;
        for (string word : words) {
            unordered_map<char, int> wordMap;
            for (char c : word) {
                wordMap[c]++;
            }
            bool skip = false;
            for (const auto &[key, val] : wordMap) {
                if (charMap[key] < val) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;
            ans += word.size();
        }
        return ans;
    }
};