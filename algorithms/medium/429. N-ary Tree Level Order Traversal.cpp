/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        if (root == nullptr) return {};
        
        vector<vector<int>> ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            
            int s = q.size();
            ans.push_back({});

            for (int i = 0; i < s; i++) {
                for (Node* n : q.front()->children) {
                    q.push(n);
                }
                ans.back().push_back(q.front()->val);
                q.pop();
            }
        }

        return ans;
    }
};