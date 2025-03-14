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
    private:
        vector<vector<int>> res;
    public:
        vector<vector<int>> decorateRecord(TreeNode* root) {
            dfs(root, 0);
            return res;
        }
    
        void dfs(TreeNode* root, int depth)
        {
            if(root == nullptr)
                return;
            if(depth >= res.size())
                res.push_back(vector<int>());   //到了新的层数，需要新建一个vector
            res[depth].push_back(root->val);
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    };