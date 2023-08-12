class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int x = 0;
        int y = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) x++;
            else m[guess[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i]) {
                if (m[secret[i]]) {
                    y++;
                    m[secret[i]]--;
                }
            }
        }
        return to_string(x) + "A" + to_string(y) + "B";
    }
};