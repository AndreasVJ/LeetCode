class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        
        unordered_map<char, int> m_p;
        for (char i : p) m_p[i]++;
        
        unordered_map<char, int> m;
        int count = 0;
        
        for (int a = 0, i = 0; i < s.size(); i++) {
            
            m[s[i]]++;
            count++;
            
            while (m[s[i]] > m_p[s[i]]) {
                m[s[a]]--;
                count--;
                a++;
            }
            
            if (count == p.size()) {
                ans.push_back(a);
                m[s[a]]--;
                count--;
                a++;
            }
            
        }
        
        return ans;
    }
};