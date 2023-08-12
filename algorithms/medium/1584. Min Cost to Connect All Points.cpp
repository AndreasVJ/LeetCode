class UnionFind {
    public:
        UnionFind(int size) : root(size), rank(size) {
            for (int i = 0; i < size; i++) {
                root[i] = i;
                rank[i] = 1;
            }
        }

        int find(int x) {
            if (root[x] == x) {
                return x;
            }
            return root[x] = find(root[x]); 
        }

        void connect(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    root[rootY] = rootX;
                }
                else if (rank[rootX] < rank[rootY]) {
                    root[rootX] = rootY;
                }
                else {
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }

        bool isConnected(int x, int y) {
            return find(x) == find(y);
        }
    
    private:
        std::vector<int> root;
        std::vector<int> rank;
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int cost = 0;
        int edges = 0;

        UnionFind uf(points.size());

        struct comp {
        bool operator()(vector<int>& a, vector<int>& b) {
                return a[2] > b[2];
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                pq.push({i, j, abs(points[i][0] -  points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }

        while (edges < points.size() - 1) {
            if (!uf.isConnected(pq.top()[0], pq.top()[1])) {
                uf.connect(pq.top()[0], pq.top()[1]);
                cost += pq.top()[2];
                edges++;
            }
            pq.pop();
        }

        return cost;
    }
};