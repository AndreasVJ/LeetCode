class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int a, b, result;
        while (pq.size() > 1) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            result = a-b;
            if (result) pq.push(result);
        }
        if (!pq.empty()) return pq.top();
        return 0;
    }
};