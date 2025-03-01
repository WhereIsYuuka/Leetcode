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
        ListNode *dummy = new ListNode(0, head);
        ListNode *p = dummy;
        for(int i = 0; i < left-1; i++)
        {
            p = p->next;
        }
        ListNode *pre = nullptr, *cur = p->next, *next;
        for(int i = 0; i < right-left+1; i++)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        p->next->next = cur;
        p->next = pre;
        return dummy->next;
    }
};