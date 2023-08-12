class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int a = 0;
        int b = s.size()-1;
        char temp;
        while (a < b) {
            while (a < b && vowels.find(s[a]) == string::npos) a++;
            while (a < b && vowels.find(s[b]) == string::npos) b--;
            temp = s[a];
            s[a] = s[b];
            s[b] = temp;
            a++;
            b--;
        }
        return s;
    }
};