class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                out.push_back({1});
            }
            else {
                vector<int> row = {1};
                for (int n = 0; n < i-1; n++) {
                    row.push_back(out[i-1][n]+out[i-1][n+1]);
                }
                row.push_back(1);
                out.push_back(row);
            }
        }
        return out;
    }
};