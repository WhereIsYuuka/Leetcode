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
        vector<vector<int>> decorateRecord(TreeNode* root) {
            if(root == nullptr)
                return {};
            vector<vector<int>> res;
            queue<TreeNode*> q;
            bool isLeftToRight = true;
            q.emplace(root);
            while(!q.empty())
            {
                vector<int> line;
                for(int i = q.size(); i > 0; i--)
                {
                    TreeNode* tmp = q.front();
                    q.pop();
                    line.emplace_back(tmp->val);
                    if(tmp->left)
                        q.emplace(tmp->left);
                    if(tmp->right)
                        q.emplace(tmp->right);
                }
                if(!isLeftToRight)
                    reverse(line.begin(), line.end());
    
                isLeftToRight = !isLeftToRight; 
                res.emplace_back(line);
            }
            return res;
        }
    };