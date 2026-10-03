/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> ump;
        while(headA && headB)
        {
            if(ump[headA])
                return headA;
            ump[headA]++;
            headA = headA->next;
            if(ump[headB])
                return headB;
            ump[headB]++;
            headB = headB->next;
        }
        while(headA)
        {
            if(ump[headA])
                return headA;
            ump[headA]++;
            headA = headA->next;
        }
        while(headB)
        {
            if(ump[headB])
                return headB;
            ump[headB]++;
            headB = headB->next;
        }
        return NULL;
    }
};