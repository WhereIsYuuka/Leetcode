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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        queue<ListNode*> que;
        for(int i = 0; i < cnt; i++)
        {
            que.push(head);
            head = head->next;
        }
        while(head != nullptr)
        {
            que.pop();
            que.push(head);
            head = head->next;
        }
        return que.front();
    }
};