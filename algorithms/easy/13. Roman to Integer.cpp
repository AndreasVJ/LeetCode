class Solution {
public:
    int romanToInt(string s) {
        int out = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'M') {
                out += 1000;
            }
            else if (s[i] == 'D') {
                out += 500;
            }
            else if (s[i] == 'C') {
                if (s[i+1] == 'M') {
                    out += 900;
                    i++;
                }
                else if (s[i+1] == 'D') {
                    out += 400;
                    i++;
                }
                else {
                    out += 100;
                }
            }
            else if (s[i] == 'L') {
                out += 50;
            }
            else if (s[i] == 'X') {
                if (s[i+1] == 'C') {
                    out += 90;
                    i++;
                }
                else if (s[i+1] == 'L') {
                    out += 40;
                    i++;
                }
                else {
                    out += 10;
                }
            }
            else if (s[i] == 'V') {
                out += 5;
            }
            else if (s[i] == 'I') {
                if (s[i+1] == 'X') {
                    out += 9;
                    i++;
                }
                else if (s[i+1] == 'V') {
                    out += 4;
                    i++;
                }
                else {
                    out += 1;
                }
            }
        }
    return out;
    }
};