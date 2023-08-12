class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;

        int a = 0;
        int b = matrix[0].size() - 1;
        int c = matrix.size() - 1;
        int d = 0;

        while (true) {
            for (int i = d; i <= b; i++) {
                ans.push_back(matrix[a][i]);
            }
            if (ans.size() == matrix[0].size() * matrix.size()) return ans;
            a++;
            for (int i = a; i <= c; i++) {
                ans.push_back(matrix[i][b]);
            }
            if (ans.size() == matrix[0].size() * matrix.size()) return ans;
            b--;
            for (int i = b; i >= d; i--) {
                ans.push_back(matrix[c][i]);
            }
            if (ans.size() == matrix[0].size() * matrix.size()) return ans;
            c--;
            for (int i = c; i >= a; i--) {
                ans.push_back(matrix[i][d]);
            }
            if (ans.size() == matrix[0].size() * matrix.size()) return ans;
            d++;
        }
    }
};