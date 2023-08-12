class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        for (int i = 0; i <= k; i++) {

            vector<int> temp(distance);

            for (vector<int>& flight : flights) {
                if (distance[flight[0]] != INT_MAX) {
                    temp[flight[1]] = min(distance[flight[0]] + flight[2], temp[flight[1]]);
                }
            }

            distance = temp;
        }

        if (distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};