class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int diff, i = 0; i < heights.size() - 1; i++) {
            diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                if (ladders > 0) {
                    pq.push(diff);
                    ladders--;
                }
                else if (!pq.empty() && diff > pq.top() && bricks >= pq.top()) {
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(diff);
                }
                else if (bricks >= diff) {
                    bricks -= diff;
                }
                else return i;
            }
        }

        return heights.size() - 1;
    }
};