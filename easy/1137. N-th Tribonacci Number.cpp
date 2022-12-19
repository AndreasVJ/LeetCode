class Solution {
public:
    int tribonacci(int n) {

        int arr[3] = {0, 1, 1};

        for (int i = 3; i <= n; i++) {
            arr[i%3] = arr[0] + arr[1] + arr[2];
        }

        return arr[n%3];
    }
};