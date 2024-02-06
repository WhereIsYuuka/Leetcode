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
    ListNode* partition(ListNode* head, int x) {     
        if(!head)
            return nullptr;
        ListNode *dummyHead1 = new ListNode(0), *dummyHead2 = new ListNode(0);
        ListNode *p1 = dummyHead1, *p2 = dummyHead2;
        while(head)
        {
            if(head->val < x)
            {
                p1->next = head;
                p1 = p1->next;
            }
            else
            {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = nullptr;
        p1->next = dummyHead2->next;
        return dummyHead1->next;
    }
};