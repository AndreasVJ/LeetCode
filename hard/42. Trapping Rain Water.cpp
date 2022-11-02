class Solution {
public:
    int trap(vector<int>& h) {
        
        int len = h.size();
            
        vector<int> leftMax(len), rightMax(len);
        leftMax[0] = h[0];
        rightMax[len-1] = h[len-1];
        
        for (int i = 1; i < len; i++) {
            leftMax[i] = max(h[i], leftMax[i-1]);
        }
        for (int i = len-2; i > 0; i--) {
            rightMax[i] = max(h[i], rightMax[i+1]);
        }
        
        int ans = 0;
        
        for (int i = 1; i < len-1; i++) {
            ans += min(leftMax[i], rightMax[i]) - h[i]; 
        }
        
        return ans;
    }
};