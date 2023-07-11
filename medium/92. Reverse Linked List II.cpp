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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* startPrev = nullptr;
        ListNode* curr = head;
        for (int i = 1; i < left-1; i++) {
            curr = curr->next;
        }
        if (left > 1) {
            startPrev = curr;
            curr = curr->next;
        }
        ListNode* start = curr;

        ListNode* temp;
        ListNode* prev = nullptr;
        for (int i = left; i < right; i++) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        start->next = curr->next;
        if (startPrev) {
            startPrev->next = curr;
            curr->next = prev;
            return head;
        }
        curr->next = prev;
        return curr;
    }
};