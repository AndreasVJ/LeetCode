class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0;
        int b = numbers.size()-1;
        while (numbers[a]+numbers[b] != target) {
            if (numbers[a]+numbers[b] > target) b--;
            else a++;
        }
        return {a+1, b+1};
    }
};