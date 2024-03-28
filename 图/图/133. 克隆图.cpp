/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }

    Node* dfs(Node* node)
    {
        if(!node)
            return nullptr;
        if(visited.count(node))
            return visited[node];
        Node* tmp = new Node(node->val);
        visited[node] = tmp;
        for(auto n : node->neighbors)
        {
            tmp->neighbors.push_back(dfs(n));
        }
        return tmp;
    }
};