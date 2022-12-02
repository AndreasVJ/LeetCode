class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int arr[100]{};
        int ans = 0;
        int n = 0;
        
        for (int h : heights) arr[h-1]++;
        
        for (int i = 0; i < 100; i++) {
            while (arr[i]-- > 0) {
                if (heights[n] != i + 1) ans++;
                n++;
            }
        }
        
        return ans;
    }
};