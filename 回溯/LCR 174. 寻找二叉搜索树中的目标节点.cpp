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
        int res, cnt;
    
    public:
        int findTargetNode(TreeNode* root, int cnt) {
            this->cnt = cnt;
            dfs(root);
            return res;
        }
    
        void dfs(TreeNode* node)
        {
            if(node == nullptr)
                return;
            if(node->right != nullptr)
                dfs(node->right);
            if(cnt == 0)
                return;
            if(--cnt == 0)
            {
                res = node->val;
                return;
            }
            if(node->left != nullptr)
                dfs(node->left);
        }
    };