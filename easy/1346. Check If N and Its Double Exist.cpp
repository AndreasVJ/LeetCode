class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int n = 0; n < arr.size(); n++) {
                if (i != n && arr[i] == 2 * arr[n]) return 1;
            }
        }
        return 0;
    }
};