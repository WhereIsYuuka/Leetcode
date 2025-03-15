/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        vector<int> decorateRecord(TreeNode* root) {
            //BFS 
            if(root == nullptr)
                return {};
            vector<int> res;
            queue<TreeNode*> que;
            que.emplace(root);
            while(!que.empty())
            {
                TreeNode* tmp = que.front();
                que.pop();
                res.emplace_back(tmp->val);
                if(tmp->left)
                    que.emplace(tmp->left);
                if(tmp->right)
                    que.emplace(tmp->right);
            }
            return res;
        }
    };