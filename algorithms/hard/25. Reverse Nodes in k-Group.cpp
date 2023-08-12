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
    ListNode* reverseKGroup(ListNode* head, int k, ListNode* prevSectionEnd = nullptr) {
        if (k == 1) return head;
        ListNode* prev = head;
        for (int i = 0; i < k; i++) {
            if (prev == nullptr) return head;
            prev = prev->next;
        }
        ListNode* temp;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            temp = curr->next;
            curr->next = prev;
            if (i != k - 1) {
                prev = curr;
                curr = temp;
            }
        }
        if (prevSectionEnd) prevSectionEnd->next = curr;
        reverseKGroup(temp, k, head);
        return curr;
    }
};