class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int a = 0;
        int b = 1;
        while (numbers[a] + numbers[b] != target) {
            if (numbers[a] + numbers[b] > target) {
                while (numbers[a] + numbers[b] > target) {
                    b--;
                }
                if (numbers[a] + numbers[b] == target) return {a+1, b+1};
                a++;
            }
            
            else if (b < n-1) {
                b++;
            }
            else a++;
        }
        return {a+1, b+1};
    }
};