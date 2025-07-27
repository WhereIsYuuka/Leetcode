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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root){
            if(!root)
                return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);
            res = max(res, l + r);
            return max(l, r) + 1;
        };
        dfs(root);
        return res;
    }
};