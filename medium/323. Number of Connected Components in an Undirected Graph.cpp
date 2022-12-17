class UnionFind {
    public:
        UnionFind(int size) : root(size), rank(size), count(size) {
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
                count--;
            }
        }

        bool connected(int x, int y) {
            return find(x) == find(y);
        }

        int getCount() {
            return count;
        }
    
    private:
        std::vector<int> root;
        std::vector<int> rank;
        int count;
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        UnionFind uf(n);

        for (vector<int> edge : edges) {
            uf.unionSet(edge[0], edge[1]);
        }

        return uf.getCount();
    }
};