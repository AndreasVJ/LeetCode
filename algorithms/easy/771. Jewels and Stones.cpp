class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int ans = 0;

        unordered_set<char> m;
        for (char c : jewels) m.insert(c);
        
        for (char c : stones) if (m.find(c) != m.end()) ans++;

        return ans;
    }
};