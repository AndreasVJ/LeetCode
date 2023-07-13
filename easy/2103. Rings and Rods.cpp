class Solution {
public:
    int countPoints(string rings) {
        uint8_t rod[100];
        for (int i = 0; i < 100; i++) rod[i] = 0;
        for (int i = 0; i < rings.size(); i += 2) {
            int rodIdx = rings[i+1] - '0';
            if (rings[i] == 'R') rod[rodIdx] |= 1;
            else if (rings[i] == 'G') rod[rodIdx] |= 2;
            else rod[rodIdx] |= 4; 
        }

        int ans = 0;
        for (int i = 0; i < 100; i++) {
            if (rod[i] == 7) ans++;
        }

        return ans;
    }
};