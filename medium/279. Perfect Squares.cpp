class Solution {
public:
    int numSquares(int n) {
        
        unordered_set<int> visited;

        vector<int> nums;
        for (int i = 1; i*i <= n; i++) nums.push_back(i*i);

        queue<pair<int, int>> q;
        for (int num : nums) {
            q.push({num, 1});
            visited.insert(num);
        }

        while (true) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                if (a == n) return b;
                for (int j = 0; j < nums.size() && a + nums[j] <= n; j++) {
                    if (visited.find(a + nums[j]) == visited.end()) {
                        q.push({a + nums[j], b + 1});
                        visited.insert(a + nums[j]);
                    }
                }
            }
        }
    }
};