struct Node
{
    Node* children[26]{};
    bool isEnd;
};

class Trie {
    public:
        Node* root = new Node();
        
        int Search(string word)
        {
            Node* node = root;
            for(char c : word)
            {
                int index = c - 'a';
                if(node->children[index] == nullptr)
                {
                    return -1;
                }
                node = node->children[index];
            }
            return node->isEnd ? 1 : 0;
        }

        void insert(string word) {
            Node* node = root;

            for(char c : word)
            {
                int index = c - 'a';
                if(node->children[index] == nullptr)
                {
                    node->children[index] = new Node();
                }
                node = node->children[index];
            }
            node->isEnd = true;
        }
        
        bool search(string word) {
            return Search(word) == 1;
        }
        
        bool startsWith(string prefix) {
            return Search(prefix) != -1;
        }
    };
    
    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */


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