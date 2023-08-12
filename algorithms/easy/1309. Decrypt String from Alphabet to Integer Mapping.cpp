class Solution {
public:
    string freqAlphabets(string s) {
        char c;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size()-2 && s[i+2] == '#') {
                c = 96+stoi(s.substr(i, 2));
                i += 2;
            }
            else {
                c = 48+s[i];
            }
            ans += c;
        }
        return ans;
    }
};