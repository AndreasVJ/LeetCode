class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> ms, mt;
        for (char c : s) ms[c]++;
        for (char c : t) {
            mt[c]++;
            if (mt[c] > ms[c]) return c;
        }
        return ' ';
    }
};