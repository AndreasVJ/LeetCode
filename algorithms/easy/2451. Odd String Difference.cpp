class Solution {
public:
    string oddString(vector<string>& words) {
        vector<int> v;
        for (int n = 1; n < words[0].size(); n++) {
            v.push_back(int(words[0][n]) - int(words[0][n-1]));
        }
        for (int i = 1; i < words.size(); i++) {
            for (int n = 1; n < words[i].size(); n++) {
                if (int(words[i][n]) - int(words[i][n-1]) != v[n-1]) {
                    if (i == 1) {
                        if (int(words[i+1][n]) - int(words[i+1][n-1]) != v[n-1]) return words[0];
                        return words[1];
                    }
                    else {
                        return words[i];                    
                    }
                }
            }
        }
        return words[0];
    }
};