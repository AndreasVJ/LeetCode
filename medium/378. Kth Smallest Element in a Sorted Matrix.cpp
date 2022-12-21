class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> pq;

        int row = 0;
        int column = 0;

        while (pq.size() != k) {
            pq.push(matrix[row][column]);
            column++;
            if (column == matrix[0].size()) {
                column = 0;
                row++;
            }
        }

        if (column != 0) {
            for (int i = column; i < matrix[0].size(); i++) {
                pq.push(matrix[row][i]);
                pq.pop();
            }
            row++;
        }

        for (int a, i = row; i < matrix.size(); i++) {
            
            a = 0;

            for (int b = matrix[0].size() / 2; b > 0; b /= 2) {
                while (a < matrix[0].size() - b && matrix[i][a + b] < pq.top()) a += b;
            }

            if (matrix[i][a] < pq.top()) {
                for (int j = 0; j <= a; j++) {
                    pq.push(matrix[i][j]);
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};