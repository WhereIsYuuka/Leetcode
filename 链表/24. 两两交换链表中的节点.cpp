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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = head, *pre = dummyHead;
        ListNode *tmp1, *tmp2;
        while(cur && cur->next)
        {
            tmp1 = cur->next;
            tmp2 = tmp1->next;

            pre->next = tmp1;
            tmp1->next = cur;
            cur->next = tmp2;

            pre = cur;
            cur = tmp2;
        }
        return dummyHead->next;
    }
};