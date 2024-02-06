class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* tmpNode = dummyHead;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            int sum = x + y + carry;
            carry = sum/10;
            tmpNode->next = new ListNode(sum%10);
            tmpNode = tmpNode->next;
            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
        }
        if(carry != 0)
        {
            tmpNode->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head1 = l1, *head2 = l2;
//         if(head1  == nullptr && head2 == nullptr)    return nullptr;
//         while(head1 != nullptr)
//         {
//             if(head2 != nullptr)
//             {
//                 head1->val += head2->val;
//                 head2 = head2->next;
//             }
//             if(head1->next == nullptr && head2 != nullptr)
//             {
//                 head1->next = head2;
//                 break;
//             }
//             head1 = head1->next;
//         }
//         head1 = l1;
//         while(head1 != nullptr)
//         {
//             if(head1->val >= 10)
//             {
//                 head1->val %= 10;
//                 if(head1->next == nullptr)
//                 {
//                     head1->next = new ListNode(0);
//                 }
//                 head1->next->val += 1;
//             }
//             head1 = head1->next;
//         }
//         return l1;
//     }
// };