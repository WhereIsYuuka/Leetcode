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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val)
            return head->next;
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr)
        {
            if(cur->val == val)
            {
                pre->next = cur->next;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};