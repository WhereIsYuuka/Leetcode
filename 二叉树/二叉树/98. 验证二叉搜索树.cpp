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
    // The reason for using long is to avoid overflow when INT_MIN is assigned to pre or INT_MAX is assigned to root_val.
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(!isValidBST(root->left) || root->val <= pre)
            return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};