class Solution {
public:
    int lengthOfLastWord(string s) {
        int b = s.size()-1;
        while (s[b] == ' ') b--;
        int a = b;
        while (a >= 0 && s[a] != ' ') a--;
        return b-a;
    }
};