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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        UnionFind uf(s.size());

        for (vector<int> pair : pairs) {
            uf.unionSet(pair[0], pair[1]);
        }

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < s.size(); i++) {
            m[uf.find(i)].push_back(i);
        }

        string ans(s.size(), 'a');
        string temp;

        for (auto const& [key, value] : m){

            temp = "";

            for (int i : value) {
                temp += s[i];
            }

            sort(temp.begin(), temp.end());

            for (int i = 0; i < temp.size(); i++) {
                ans[value[i]] = temp[i];
            }
        }

        return ans;
    }
};