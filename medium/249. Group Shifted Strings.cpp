class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {

        vector<vector<string>> ans;

        unordered_map<string, vector<int>> m;

        for (int i = 0; i < strings.size(); i++) {
            
            int shift = strings[i][0] - 'a';
            string key = "";

            for (char c : strings[i]) {
                key += (c + 26 - shift) % 26 + 'a';
            }

            m[key].push_back(i);
        }

        for (auto const& [key, indexes] : m) {
            ans.push_back({});
            for (int i : indexes) {
                ans.back().push_back(strings[i]);
            }
        }
        
        return ans;
    }
};