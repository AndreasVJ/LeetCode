class Solution {
public:
    bool equalFrequency(string word) {
        int freq[26];
        fill(freq, freq + 26, 0);
        for (char c : word) freq[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            unordered_set<int> s;
            for (int j = 0; j < 26; j++) {
                if (freq[j] == 0 || j == i) continue;
                s.insert(freq[j]);
            }
            if (s.size() == 0) return true;
            if (s.size() == 1) {
                if (freq[i] == 1 || freq[i] - 1 == *s.begin()) return true;
            }
        }

        return false;
    }
};