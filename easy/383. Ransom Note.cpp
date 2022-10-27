class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector l(26, 0);
        for (char c : magazine) {
            l[int(c)-97]++;
        }
        for (char c : ransomNote) {
            if (l[int(c)-97] == 0) return 0;
            l[int(c)-97]--;
        }
        return 1;
    }
};