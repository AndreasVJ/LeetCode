class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        struct comp {
            bool operator()(pair<int, int>& a, pair<int, int>& b) {
                return a.first > b.first;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> meetings;

        for (vector<int> interval : intervals) meetings.push({interval[0], interval[1]});

        priority_queue<int, vector<int>, greater<int>> end_times;

        int ans = 1;
        int current = 0;

        while (!meetings.empty()) {

            current++;

            end_times.push(meetings.top().second);

            if (meetings.top().first >= end_times.top()) {
                current--;
                end_times.pop();
            
            }

            meetings.pop();

            ans = max(ans, current);
        }

        return ans;
    }
};