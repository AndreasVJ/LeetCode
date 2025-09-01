struct Compare {
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        double aImprovement = double(a[0]+1) / double(a[1]+1) - double(a[0]) / double(a[1]);
        double bImprovement = double(b[0]+1) / double(b[1]+1) - double(b[0]) / double(b[1]);
        return aImprovement < bImprovement;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<
            std::vector<int>,
            std::vector<std::vector<int>>,
            Compare
        > pq;

        for (int i = 0; i < classes.size(); i++) {
            pq.push(classes[i]);
        }

        while (extraStudents) {
            extraStudents--;
            vector<int> top = pq.top();
            pq.pop();
            top[0]++;
            top[1]++;
            pq.push(top);
        }

        double ans = 0;
        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            ans += double(top[0]) / double(top[1]);
        }
        ans /= classes.size();

        return ans;
    }
};
