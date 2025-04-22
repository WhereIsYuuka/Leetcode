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
        ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
            ListNode* res = new ListNode(0);
            ListNode* tmp = res;
            while(l1 != nullptr && l2 != nullptr)
            {
                if(l1->val <= l2->val)
                {
                    tmp->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    tmp->next = l2;
                    l2 = l2->next;
                }
                tmp = tmp->next;
            }
            if(l1 == nullptr)
                tmp->next = l2;
            if(l2 == nullptr)
                tmp->next = l1;
    
            return res->next;
        }
    };