class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths) {

        if (path.back() == graph.size() - 1) {
            paths.push_back(path);
        }
        else {
            for (int node : graph[path.back()]) {
                path.push_back(node);
                dfs(graph, path, paths);
                path.pop_back();
            }
        }

    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> paths;
        vector<int> path = {0};

        dfs(graph, path, paths);
        
        return paths;
    }
};