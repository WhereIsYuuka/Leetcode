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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(0, head);
        int len = 0;
        ListNode *p = head;
        while(p != nullptr)
        {
            len++;
            p = p->next;    
        }
        p = dummyHead;
        ListNode *pre = nullptr, *cur = p->next, *next;
        while(len >= k)
        {
            len -= k;
            for(int i = 0; i < k; i++)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            ListNode *tmp = p->next;
            p->next->next = cur;
            p->next = pre;
            p = tmp;
        }
        return dummyHead->next;     
    }
};

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode *dummy = new ListNode, *pre = NULL, *tmp;
//         dummy->next = head;
//         ListNode* cur = head, *p = dummy;
//         int len = 0;
//         while(cur != nullptr)
//         {
//             len++;
//             cur = cur->next;
//         }
//         cur = head;
//         int time = len/k;
//         for(int i = 0; i < time; i++)
//         {
//             for(int i = 0; i < k; i ++)
//             {
//                 tmp = cur->next;
//                 cur->next = pre;
//                 pre = cur;
//                 cur = tmp;
//             }
//             tmp = p->next;
//             p->next->next = cur;
//             p->next = pre;
//             p = tmp;
//         }
//         return dummy->next;
//     }
// };