class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> visited;
        for (string s : deadends) visited.insert(s);

        if (visited.find("0000") != visited.end()) return -1;

        queue<string> q;
        q.push("0000");

        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int n = 0; n < size; n++) {
                for (int i = 0; i < 4; i++) {

                    string comb = q.front();
                    if (comb == target) return count;

                    for (int j = -1; j <= 1; j += 2) {
                        comb[i] = (q.front()[i] - '0' + j + 10)%10 + '0';
                        if (visited.find(comb) == visited.end()) {
                            q.push(comb);
                            visited.insert(comb);
                        }
                    }
                }
                q.pop();
            }
            count++;
        }

        return -1;
    }
};