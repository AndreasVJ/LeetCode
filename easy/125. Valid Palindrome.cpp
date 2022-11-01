class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for (char i : s) {
            if (isalnum(i)) a += tolower(i);
        }
        for (int i = 0; i < a.size()/2; i++) {
            if (a[i] != a[a.size()-1-i]) return 0;
        }
        return 1;
    }
};