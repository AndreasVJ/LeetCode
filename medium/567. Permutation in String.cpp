class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> m1;
        for (char c : s1) m1[c]++;
        
        unordered_map<char, int> m2;
        
        int count = 0;
        int a = 0;
        
        for (int b = 0; b < s2.size(); b++) {
            if (m1.find(s2[b]) == m1.end()) {
                a = b+1;
                m2.clear();
                count = 0;
            }
            else {
                m2[s2[b]]++;
                if (m2[s2[b]] == m1[s2[b]]) count++;
                if (count == m1.size()) return 1;
                while (m2[s2[b]] > m1[s2[b]]) {
                    m2[s2[a]]--;
                    if (m2[s2[a]] == m1[s2[a]]-1) count--;
                    a++;
                }
            }
        }
        
        return 0;
    }
};