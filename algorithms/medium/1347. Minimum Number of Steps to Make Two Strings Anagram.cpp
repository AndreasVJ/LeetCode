class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCount(26, 0);
        vector<int> tCount(26, 0);

        for (char c : s) sCount[c-'a']++;
        for (char c : t) tCount[c-'a']++;

        int diff = 0;

        for (int i = 0; i < 26; i++) {
            diff += abs(sCount[i] - tCount[i]);
        }

        return diff/2 + diff%2;
    }
};