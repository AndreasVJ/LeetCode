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
        
        ListNode* curr = l1;
        ListNode* curr2 = l2;

        bool carry;

        while (curr && curr2) {
            curr->val += curr2->val + carry;
            carry = curr->val >= 10;
            curr->val %= 10;
            if ((curr2->next || carry) && !curr->next) {
                curr->next = new ListNode(0);
            }
            curr = curr->next;
            curr2 = curr2->next;
        }

        while (curr) {
            curr->val += carry;
            carry = curr-> val >= 10;
            curr->val %= 10;
            if (carry && !curr->next) {
                curr->next = new ListNode(0);
            }
            curr = curr->next;
        }

        // if (carry) curr->next = new ListNode(1);
        return l1;
    }
};