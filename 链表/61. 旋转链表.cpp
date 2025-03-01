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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *slow = dummyHead, *fast = dummyHead;
        int len = 0;
        while(slow->next)
        {
            len++;
            slow = slow->next;
        }
        slow = dummyHead;
        int step = k % len;
        for(int i = 0; i < step; i++)
        {
            fast = fast->next;
        }
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = dummyHead->next;
        dummyHead->next = slow->next;
        slow->next = nullptr;
        return dummyHead->next;
    }
};