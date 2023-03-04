/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {

        if (!head) {
            Node* n = new Node(insertVal);
            n->next = n;
            return n;
        }

        if (head == head->next) {
            head->next = new Node(insertVal);
            head->next->next = head;
            return head;
        }

        Node* curr = head;

        while (!(curr->val <= insertVal) || !(insertVal <= curr->next->val)) {
            if (curr->next == head) break;
            if (curr->next->val < curr->val && (insertVal <= curr->next->val || insertVal >= curr->val)) break;
            curr = curr->next;
        }

        Node* temp = curr->next;
        curr->next = new Node(insertVal);
        curr->next->next = temp;

        return head;
    }
};