class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for (char i : magazine) {
            count[i-97]++;
        }
        for (char i : ransomNote) {
            if (count[i-97] == 0) return 0;
            count[i-97]--;
        }
        return 1;
    }
};