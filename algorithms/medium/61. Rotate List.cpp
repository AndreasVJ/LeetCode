/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head) return head;
        
        vector<int> values;
        ListNode* curr = head;

        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;
        k %= values.size();

        for (int i = 0; i < values.size(); i++) {
            curr->val = values[(i - k + values.size())%values.size()];
            curr = curr->next;
        }

        return head;
    }
};