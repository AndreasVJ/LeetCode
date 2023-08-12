class Solution {
public:
    int maxArea(vector<int>& height) {
        int a = 0;
        int b = height.size()-1;
        int ans = 0;
        while (a < b) {
            ans = max(ans, (b-a)*min(height[a], height[b]));
            if (height[a] < height[b]) a++;
            else b--;
        }
        return ans;
    }
};