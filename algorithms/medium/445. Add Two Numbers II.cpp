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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);

        ListNode* prev = nullptr;
        bool carry = false;
        while (l1) {
            if (l2) {
                l1->val += l2->val;
                l2 = l2->next;
            }
            l1->val += carry;
            carry = l1->val >= 10;
            l1->val %= 10;
            ListNode* temp = l1->next;
            l1->next = prev;
            prev = l1;
            l1 = temp;
        }

        while (l2) {
            l2->val += carry;
            carry = l2->val >= 10;
            l2->val %= 10;
            ListNode* temp = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = temp;
        }

        if (carry) {
            ListNode* head = new ListNode(1);
            head->next = prev;
            return head;
        }

        return prev;
    }

    ListNode* reverseLinkedList(ListNode* l1) {
        ListNode* prev = nullptr;
        while (l1) {
            ListNode* temp = l1->next;
            l1->next = prev;
            prev = l1;
            l1 = temp;
        }
        return prev;
    }
};