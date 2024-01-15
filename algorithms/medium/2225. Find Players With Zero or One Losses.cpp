class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;
        for (vector<int> match : matches) {
            losses[match[0]];
            losses[match[1]]++;
        }

        vector<vector<int>> ans(2);
        for (const auto &[person, lossCount] : losses) {
            cout << person << " " << lossCount << "\n";
            if (lossCount == 0){
                ans[0].push_back(person);
            }
            else if (lossCount == 1) {
                ans[1].push_back(person);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};