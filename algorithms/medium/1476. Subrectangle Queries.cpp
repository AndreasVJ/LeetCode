class SubrectangleQueries {
public:
    int rect[100][100];

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        for (int y = 0; y < rectangle.size(); y++) {
            for (int x = 0; x < rectangle[0].size(); x++) {
                rect[y][x] = rectangle[y][x];
            }
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int y = row1; y <= row2; y++) {
            for (int x = col1; x <= col2; x++) {
                rect[y][x] = newValue;
            }
        }
        
    }
    
    int getValue(int row, int col) {
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */