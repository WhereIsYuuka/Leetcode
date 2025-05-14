/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        unordered_map<Node*, Node*> ump;
        Node *cur = head;
        while(cur != NULL)
        {
            ump[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur != NULL)
        {
            ump[cur]->next = ump[cur->next];
            ump[cur]->random = ump[cur->random];
            cur = cur->next;
        }
        return ump[head];
    }
};