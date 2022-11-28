class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        if (s == "") return {""};
        
        vector<string> ans, v;
        
        if (isdigit(s[0])) {
            v = letterCasePermutation(s.substr(1, s.size()));
            for (string i : v) {
                ans.push_back(string(1, s[0]) + i);
            }
        }
        else {
            vector<string> v = letterCasePermutation(s.substr(1, s.size()));
            
            for (string i : v) {
                ans.push_back(string(1, tolower(s[0])) + i);
                ans.push_back(string(1, toupper(s[0])) + i);
            }
        }
        
        return ans;
    }
};