class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> m;
        unordered_set<int> s;
        
        for (int i : arr) m[i]++;
        for (auto &[k, v] : m) {
            if (!s.insert(v).second) return 0;
        }
        
        return 1;
    }
};