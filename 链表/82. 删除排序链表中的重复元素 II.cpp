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
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *p = dummyHead;
        while(p->next && p->next->next)
        {
            int tmp = p->next->val;
            if(p->next->next->val == tmp)
            {
                while(p->next && p->next->val == tmp)
                {
                    ListNode *tmp = p->next;
                    p->next = p->next->next;
                    delete tmp;
                }
            }
            else
            {
                p = p->next;
            }
        }
        return dummyHead->next;
    }
};