class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int stick : sticks) pq.push(stick);

        int price = 0;
        int newStick;

        while (pq.size() != 1) {
            newStick = pq.top();
            pq.pop();
            newStick += pq.top();
            pq.pop();

            pq.push(newStick);
            price += newStick;
        }

        return price;
    }
};