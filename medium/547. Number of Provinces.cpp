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

        void unionSet(int x, int y) {
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

        bool connected(int x, int y) {
            return find(x) == find(y);
        }
    
    private:
        std::vector<int> root;
        std::vector<int> rank;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        UnionFind uf(isConnected.size());

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = i; j < isConnected.size(); j++) {
                if (isConnected[i][j]) uf.unionSet(i, j);
            }
        }

        unordered_set<int> s;
        
        for (int i = 0; i < isConnected.size(); i++) {
            s.insert(uf.find(i));
        }

        return s.size();
    }
};