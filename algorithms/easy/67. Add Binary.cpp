class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans = "";
        
        int c = a.size() - 1;
        int d = b.size() - 1;
        int n = 0;
        while (c >= 0 || d >= 0 || n) {
            if (c >= 0) {
                if (a[c] - '0') n++;
                c--;
            }
            if (d >= 0) {
                if (b[d] - '0') n++;
                d--;
            }
            ans += char(n%2 + '0');
            n /= 2;
        }
        
        char temp;
        
        for (int i = 0; i < ans.size()/2; i++) {
            temp = ans[i];
            ans[i] = ans[ans.size() - i - 1];
            ans[ans.size() - i - 1] = temp;
        }
        
        return ans;
    }
};