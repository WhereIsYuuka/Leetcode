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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *slow = dummyHead, *fast = dummyHead;
        for(int i = 0; i < n+1; i++)
        {
            fast = fast->next;
        }
        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummyHead->next;
    }
};


// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* list = new ListNode(0);
//         list->next = head;
//         ListNode* fast = list, *slow = list;
//         n++;
//         while(n-- && fast != nullptr)
//         {
//             fast = fast->next;
//         }
//         while(fast != nullptr)
//         {
//             fast = fast->next;
//             slow = slow->next;
//         }
//         ListNode* tmp = slow->next;
//         slow->next = slow->next->next;
//         delete tmp;
//         return list->next;
//     }
// };