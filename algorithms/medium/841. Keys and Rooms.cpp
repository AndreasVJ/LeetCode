class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int count = 0;
        unordered_set<int> keys(rooms.size());
        keys.insert(0);

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            
            count++;

            for (int key : rooms[q.front()]) {
                if (keys.find(key) == keys.end()) {
                    keys.insert(key);
                    q.push(key);
                }
            }

            q.pop();
        }

        return count == rooms.size();
    }
};