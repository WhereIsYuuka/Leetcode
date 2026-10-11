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
    ListNode* FindMid(ListNode* node)
    {
        ListNode* tmpNode = node;
        ListNode* slow = node;
        ListNode* fast = node;
        while(fast && fast->next)
        {
            tmpNode = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tmpNode->next = nullptr;
        return slow;
    }

    ListNode* mergeList(ListNode* list1, ListNode* list2)
    {
        ListNode dummyHead;
        ListNode* cur = &dummyHead;
        while(list1 && list2)
        {
            if(list1->val >= list2->val)
            {
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            }
            else
            {
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            }
        }
        if(list1)
            cur->next = list1;
        if(list2)
            cur->next = list2;
        return dummyHead.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* mid = FindMid(head);
        head = sortList(head);
        mid = sortList(mid);
        return mergeList(head, mid);
    }
};