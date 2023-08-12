class Solution {
public:
    int kthGrammar(int n, int k) {

        n--; k--;

        bool curr = 0;
        int pos = 0;

        for (int i = 1; i <= n; i++) {
            int half = 1 << (n-i);
            if (pos + half <= k) {
                if (curr) curr = 0; 
                else curr = 1;
                pos += half;
            }
        }

        return curr;
    }
};