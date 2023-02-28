class Solution {
public:
    int dp(int i, int day, vector<int>& jobDifficulty, int d, vector<vector<int>>& cache) {

        int best = INT_MAX;
        int mostDifficult = 0;

        if (day + 1 == d) {
            for (int j = i; j < jobDifficulty.size(); j++) {
                mostDifficult = max(mostDifficult, jobDifficulty[j]);
            }
            return mostDifficult;
        }
        int j = i;
        for (int j = i; jobDifficulty.size() - j >= d - day; j++) {

            mostDifficult = max(mostDifficult, jobDifficulty[j]);

            if (cache[j + 1][day + 1] == -1) {
                cache[j + 1][day + 1] = dp(j + 1, day + 1, jobDifficulty, d, cache);
            }

            best = min(best, cache[j + 1][day + 1] + mostDifficult);
        }

        return best;
    }


    int minDifficulty(vector<int>& jobDifficulty, int d) {

        if (jobDifficulty.size() < d) return -1;

        vector<vector<int>> cache(jobDifficulty.size(), vector<int>(d, -1));
        
        return dp(0, 0, jobDifficulty, d, cache);
    }
};