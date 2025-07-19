class LRUCache {
public:
    struct ListNode {
        int key, val;
        ListNode *prev, *next;
        ListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
        ListNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };

    ListNode *head, *tail;
    unordered_map<int, ListNode*> listMp;
    int _capacity, curSize;

    LRUCache(int capacity) {
        _capacity = capacity;
        curSize = 0;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!listMp.count(key))  //没找到
            return -1;
        ListNode *tmp = listMp[key];
        RemoveNode(tmp);
        MoveNodeToHead(tmp);
        return tmp->val;
    }
    
    void put(int key, int value) {
        if(listMp.count(key))
        {
            ListNode *tmp = listMp[key];
            tmp->val = value;
            RemoveNode(tmp);
            MoveNodeToHead(tmp);
        }
        else
        {
            if(curSize == _capacity)    //超出最大容量
            {
                ListNode *tmp = tail->prev;
                RemoveNode(tmp);
                listMp.erase(tmp->key);
                curSize--;
            }
            ListNode *tmp = new ListNode(key, value);
            listMp[key] = tmp;
            MoveNodeToHead(tmp);
            curSize++;

        }
    }

    void RemoveNode(ListNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void MoveNodeToHead(ListNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// class LRUCache {
// public:
//     struct ListNode{
//         int key;
//         int val;
//         ListNode *next;
//         ListNode *pre;
//         ListNode() : val(0), key(0), pre(nullptr), next(nullptr) {}
//         ListNode(int k, int v) : val(v), key(k), pre(nullptr), next(nullptr) {}
//     };
//     unordered_map<int, ListNode*> theNum;
//     ListNode *head, *tail;
//     int _capacity, curSize;

//     LRUCache(int capacity) {
//         _capacity = capacity, curSize = 0;
//         head = new ListNode();
//         tail = new ListNode();
//         head->next = tail;
//         tail->pre = head;
//     }
    
//     int get(int key) {  
//         if(!theNum.count(key))  
//             return -1;
//         ListNode* node = theNum[key];
//         removeNode(node);
//         putNodeToHead(node);
//         return theNum[key]->val;
//     }
    
//     void put(int key, int value) {
//         if(theNum.count(key))
//         {
//             ListNode* node = theNum[key];
//             node->val = value;
//             removeNode(node);
//             putNodeToHead(node);
//         }
//         else
//         {
//             if(curSize == _capacity)
//             {
//                 ListNode* node = tail->pre;
//                 theNum.erase(node->key);
//                 removeNode(node);
//                 curSize--;
//             }
//             ListNode* node = new ListNode(key, value);
//             putNodeToHead(node);
//             theNum[key] = node;
//             curSize++;
//         }
//     }

//     void removeNode(ListNode* node){
//         node->pre->next = node->next;
//         node->next->pre = node->pre;
//     }

//     void putNodeToHead(ListNode* node){
//         node->pre = head;
//         node->next = head->next;
//         head->next->pre = node;
//         head->next = node;
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


 /*class LRUCache {
private:
    struct ListNode{
        int key, val;
        ListNode *pre, *next;
        ListNode(int key = 0, int val = 0) : key(key), val(val), pre(nullptr), next(nullptr) {}
    };
    unordered_map<int, ListNode*> listMp;
    ListNode *dummyhead;
    int _capacity;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
        dummyhead = new ListNode();
        dummyhead->next = dummyhead;
        dummyhead->pre = dummyhead;
    }
    // 
    int get(int key) {
        if(!listMp.count(key))
            return -1;

        ListNode* tmp = listMp[key];
        RemoveHead(tmp);
        MoveNodeToHead(tmp);
        return tmp->val;
    }
    
    void put(int key, int value) {
        if(listMp.count(key))
        {
            ListNode* tmp = listMp[key];
            tmp->val = value;
            RemoveHead(tmp);
            MoveNodeToHead(tmp);
            return;
        }
        ListNode* node = new ListNode(key, value);
        listMp[key] = node;
        MoveNodeToHead(node);
        if(listMp.size() > _capacity)
        {
            ListNode* tmp = dummyhead->pre;
            RemoveHead(tmp);
            listMp.erase(tmp->key);
        }
    }

    void MoveNodeToHead(ListNode *node)
    {
        node->pre = dummyhead;
        node->next = dummyhead->next;
        dummyhead->next->pre = node;
        dummyhead->next = node;
    }

    void RemoveHead(ListNode *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */