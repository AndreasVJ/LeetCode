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

    private:
        vector<int> root;
        vector<int> rank;
};


class Solution {
public:
    int largestComponentSize(vector<int>& nums) {

        int maxVal = 0;
        for (int num : nums) maxVal = max(maxVal, num);
        
        UnionFind uf(maxVal + 1);

        for (int num : nums) {
            for (int factor = 2; factor <= int(sqrt(num)); factor++) {
                if (num % factor == 0) {
                    uf.unionSet(num, factor);
                    uf.unionSet(num, num  / factor);
                }
            }
        }

        int ans = 0;
        unordered_map<int, int> m;

        for (int num : nums) m[uf.find(num)]++;

        for (auto const& [key, value] : m) ans = max(ans, value);

        return ans;
    }
};