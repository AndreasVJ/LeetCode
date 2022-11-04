class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<tuple<string, int, int>> q;
        q.push({"", 0, 0});
        tuple<string, int, int> curr;
        while (!q.empty()) {
            curr = q.front();
            if (get<0>(curr).size() == 2*n) ans.push_back(get<0>(curr));
            else {
                if (get<1>(curr) < n) q.push({get<0>(curr)+'(', get<1>(curr)+1, get<2>(curr)});
                if (get<2>(curr) < get<1>(curr)) q.push({get<0>(curr)+')', get<1>(curr), get<2>(curr)+1});
            }
            q.pop();
        }
        return ans;
    }
};