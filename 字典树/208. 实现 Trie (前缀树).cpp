class Trie {
private:
    struct Node{
        Node* next[26];
        bool isEnd = false;
    };

    Node* root = new Node();

    int find(string str)
    {
        Node* cur = root;
        for(auto ch : str)
        {
            int idx = ch - 'a';
            if(cur->next[idx] == nullptr)
                return 0;
            cur = cur->next[idx];
        }
        return cur->isEnd ? 2 : 1;
    }
public:
    Trie() {
        
    }
    
    
    void insert(string word) {
        Node* cur = root;
        for(auto it : word)
        {
            int idx = it - 'a';
            if(cur->next[idx] == nullptr)
            {
                cur->next[idx] = new Node();
                cur = cur->next[idx];
            }
            else
            {
                cur = cur->next[idx];
            }
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return find(word) == 2;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != 0;
    }
};

// struct Node
// {
//     Node* children[26]{};
//     bool isEnd;
// };

// class Trie {
//     public:
//         Node* root = new Node();
        
//         int Search(string word)
//         {
//             Node* node = root;
//             for(char c : word)
//             {
//                 int index = c - 'a';
//                 if(node->children[index] == nullptr)
//                 {
//                     return -1;
//                 }
//                 node = node->children[index];
//             }
//             return node->isEnd ? 1 : 0;
//         }

//         void insert(string word) {
//             Node* node = root;

//             for(char c : word)
//             {
//                 int index = c - 'a';
//                 if(node->children[index] == nullptr)
//                 {
//                     node->children[index] = new Node();
//                 }
//                 node = node->children[index];
//             }
//             node->isEnd = true;
//         }
        
//         bool search(string word) {
//             return Search(word) == 1;
//         }
        
//         bool startsWith(string prefix) {
//             return Search(prefix) != -1;
//         }
//     };


// class Trie {
// private:
//     struct Node{
//         bool isEnd;
//         Node *child[26]{};
//     };

// public:
//     Node *root = new Node();

//     Trie() {
        
//     }
    
//     void insert(string word) {
//         Node *node = root;

//         for(auto ch : word)
//         {
//             int idx = ch - 'a';
//             if(node->child[idx] == nullptr)
//             {
//                 node->child[idx] = new Node();
//             }
//             node = node->child[idx];
//         }
//         node->isEnd = true;
//     }
    
//     bool search(string word) {
//         return Search(word) == 1;
//     }
    
//     bool startsWith(string prefix) {
//         return Search(prefix) != -1;
//     }

//     int Search(string word)
//     {
//         Node *node = root;

//         for(auto ch : word)
//         {
//             int idx = ch - 'a';
//             if(node->child[idx] == nullptr)
//                 return -1;
//             node = node->child[idx];
//         }
//         return node->isEnd ? 1 : 0;
//     }
// };

// /**
//  * Your Trie object will be instantiated and called as such:
//  * Trie* obj = new Trie();
//  * obj->insert(word);
//  * bool param_2 = obj->search(word);
//  * bool param_3 = obj->startsWith(prefix);
//  */