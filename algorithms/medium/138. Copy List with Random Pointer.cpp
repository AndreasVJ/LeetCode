/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;

    Node* copyRandomList(Node* head) {
        
        if (!head) return nullptr;
        if (m.find(head) != m.end()) return m[head];

        Node* copy = new Node(head->val);
        m[head] = copy;

        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);

        return copy;
    }
};