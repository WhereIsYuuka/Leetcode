/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    vector<Node*> res;
public:
    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }

    void dfs(Node* root, int depth)
    {
        if(!root)
            return;
        if(res.size() == depth)
        {
            res.push_back(root);
        }
        else
        {
            res[depth]->next = root;
            res[depth] = root;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};
