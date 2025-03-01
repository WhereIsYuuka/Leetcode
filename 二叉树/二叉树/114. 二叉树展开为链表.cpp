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
    TreeNode *pre = nullptr;
    void flatten(TreeNode* root) {
        if(!root)
            return;
        if(pre)
        {
            pre->left = nullptr;
            pre->right = root;
        }
        pre = root;
        TreeNode *right = root->right;
        flatten(root->left);
        flatten(right);
    }
};