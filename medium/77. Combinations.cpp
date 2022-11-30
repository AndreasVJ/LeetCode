class Solution {
public:
    
    vector<int> combination;
    vector<vector<int>> ans;
    int a = 1;
    
    void search(int n, int k) {
        if (combination.size() == k) ans.push_back(combination);
        else {
            for (int i = a; i <= n; i++) {
                combination.push_back(i);
                a++;
                search(n, k);
                a = combination.back() + 1;
                combination.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        search(n, k);
        return ans;
    }
};