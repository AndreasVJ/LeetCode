class Solution {
public:
    int titleToNumber(string columnTitle) {
        int a = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            a += (int(columnTitle[columnTitle.size()-1-i])-64)*pow(26, i);
        }
        return a;
    }
};