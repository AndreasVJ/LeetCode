class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;

        unordered_map<string, vector<int>> m;

        for (int i = 0; i < strs.size(); i++) {

            string temp = strs[i];

            sort(temp.begin(), temp.end());
            m[temp].push_back(i);
        }

        for (auto const& [key, indexes] : m) {
            ans.push_back({});
            for (int i : indexes) {
                ans.back().push_back(strs[i]);
            }
        }

        return ans;
    }
};