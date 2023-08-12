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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* temp = head;
        ListNode* next = head->next;
        while (next) {
            while (next->val == temp->val) {
                next = next->next;
                if (!next) {
                    temp->next = nullptr;
                    return head;
                }
            }
            temp->next = next;
            temp = temp->next;
            next = next->next;
        }
        return head;
    }
};