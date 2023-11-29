class Solution {
public:
    string maximumBinaryString(string b) {
        int i = 0;
        while (i < b.size() && b[i] == '1') {
            i++;
        }
        if (i == b.size()) return b;

        int zeros = 0;
        for (int j = i; j < b.size(); j++) {
            if (b[j] == '0') {
                zeros++;
                b[j] = '1';
            }
        }
        b[i+zeros-1] = '0';
        
        return b;
    }
};