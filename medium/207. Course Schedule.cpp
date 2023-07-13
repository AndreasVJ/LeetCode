class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<int> numPrerequisites(numCourses);
        for (vector<int> p : prerequisites) {
            v[p[1]].push_back(p[0]);
            numPrerequisites[p[0]]++;
        }

        queue<int> canTake;
        for (int i = 0; i < numCourses; i++) {
            if (numPrerequisites[i] == 0) canTake.push(i);
        }

        while(!canTake.empty()) {
            int course = canTake.front();
            canTake.pop();
            numCourses--;

            for (int c : v[course]) {
                numPrerequisites[c]--;
                if (numPrerequisites[c] == 0) canTake.push(c);
            }
        }

        return numCourses == 0;
    }
};