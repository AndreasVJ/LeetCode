class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size()/2; i++) {
            if (s.size() % i == 0) {
                int numSubstrings = s.size()/i;
                bool repeat = true;
                for (int j = 1; j < numSubstrings; j++) {
                    if (s.substr(0, i) != s.substr(j*i, i)) {
                        repeat = false;
                        break;
                    }
                }
                if (repeat) return true;
            }
        }
        return false;
    }
};