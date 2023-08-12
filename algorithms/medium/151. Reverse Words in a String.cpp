class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> words = {""};
        string ans = "";
        
        
        for (char c : s) {
            if (c == ' ') {
                if (words.back() != "") words.push_back("");
            }
            else words.back() += c;
        }
        
        if (words.back() == "") words.pop_back();
        
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i != 0) ans += " ";
        }
        
        return ans;
    }
};