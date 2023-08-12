class Solution {
public:
    string decodeString(string s) {
        if (s.size() == 1) return s;
        int n = s.size();
        string ans = "";
        string temp;
        int num;
        queue<pair<int, string>> q;
        int a;
        int b;
        int p;
        for (int i = 0; i < n; i++) {
            if (s[i] < 58) {
                if (s[i+1] < 58) {
                    i++;
                    if (s[i+1] < 58) {
                        i++;
                        num = stoi(s.substr(i-2, 3));
                    }
                    else num = stoi(s.substr(i-1, 2));
                }
                else num = stoi(s.substr(i, 1));
                a = 1;
                b = 0;
                p = i+2;
                while (a != b) {
                    if (s[p] == '[') a++;
                    else if (s[p] == ']') b++;
                    p++;
                }
                q.push({num, s.substr(i+2, p-i-3)});
                i = p-1;
            }
            else q.push(make_pair(1, s.substr(i, 1)));
        }
        
        while (!q.empty()) {
            cout << q.front().first << " " << q.front().second << "\n";
            temp = decodeString(q.front().second);
            for (int i = 0; i < q.front().first; i++) {
                ans += temp;
            }
            q.pop();
        }
        
        return ans;
    }
};