class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<int> ans(k);
        priority_queue<pair<int, int>> q;

        for (int a, i = 0; i < mat.size(); i++) {
            a = 0;
            for (int b = mat[0].size()/2; b > 0; b /= 2) {
                while (a < mat[0].size() - b && mat[i][a + b] != 0) a += b;
            }
            if (mat[i][a]) a++;
            q.push({a, i});
            if (q.size() > k) q.pop();
        }

        for (int i = k - 1; i >= 0; i--) {
            ans[i] = q.top().second;
            q.pop();
        }

        return ans;
    }
};