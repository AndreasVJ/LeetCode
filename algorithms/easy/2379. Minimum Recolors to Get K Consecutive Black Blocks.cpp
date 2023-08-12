class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int a = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') a++;
        }
        int best = a;
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') a++;
            if (blocks[i-k] == 'W') a--;
            best = min(best, a);
        }
        return best;
    }
};