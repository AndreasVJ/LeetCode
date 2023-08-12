class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1) return {0};

        vector<unordered_set<int>> adjacencyList(n);
        for (vector<int> edge : edges) {
            adjacencyList[edge[0]].insert(edge[1]);
            adjacencyList[edge[1]].insert(edge[0]);
        }
        
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (adjacencyList[i].size() == 1) {
                q.push(i);
            }
        }

        while (q.size() != n) {

            int size = q.size();

            for (int i = 0; i < size; i++) {
                
                int node = *adjacencyList[q.front()].begin();
                adjacencyList[node].erase(q.front());

                if (adjacencyList[node].size() == 1) {
                    q.push(node);
                }

                q.pop();
                n--;
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};