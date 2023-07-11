class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) return addStrings(num2, num1);
        
        string ans = "";
        int sum;
        bool carry = false;
        for (int i = 1; i <= num2.size(); i++) {
            sum = num1[num1.size() - i] + num2[num2.size() - i] - 2*('0') + carry;
            carry = sum/10;
            ans += '0' + sum%10;
        }
        for (int i = 1; i <= num1.size() - num2.size(); i++) {
            sum = num1[num1.size() - num2.size() - i] - '0' + carry;
            carry = sum/10;
            ans += '0' + sum%10; 
        }

        if (carry) ans += '1';
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};