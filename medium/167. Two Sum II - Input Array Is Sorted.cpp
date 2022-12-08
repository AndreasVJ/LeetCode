class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int a = 0;
        int b = numbers.size()-1;

        while (numbers[a]+numbers[b] != target) {
            for (int k = (b - a)/2; k > 0; k /= 2) {
                while (b - k > a && numbers[a] + numbers[b - k] > target) b -= k;
                if (numbers[a] + numbers[b] > target) b--;
                while (a < b - k && numbers[a + k] + numbers[b] < target) a += k;
                if (numbers[a] + numbers[b] < target) a++;
            }
        }
        return {a+1, b+1};
    }
};