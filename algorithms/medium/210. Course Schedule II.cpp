class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> prerequisitesLeft(numCourses);
        vector<vector<int>> adjacencyList(numCourses);
        queue<int> q;

        for (vector<int> v : prerequisites) {
            adjacencyList[v[1]].push_back(v[0]);
            prerequisitesLeft[v[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (prerequisitesLeft[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {

            ans.push_back(q.front());

            for (int course : adjacencyList[q.front()]) {
                prerequisitesLeft[course]--;
                if (prerequisitesLeft[course] == 0) {
                    q.push(course);
                }
            }

            q.pop();
        }

        for (int num : prerequisitesLeft) {
            if (num != 0) return {};
        }
        
        return ans;
    }
};