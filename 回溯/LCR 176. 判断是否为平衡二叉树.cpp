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
        bool isBalanced(TreeNode* root) {
            return FindDepth(root) != -1 ? true : false;
        }
    
        int FindDepth(TreeNode* root)
        {
            if(root == nullptr)
                return 0;
            int left = FindDepth(root->left);
            if(left == -1)
                return -1;
            int right = FindDepth(root->right);
            if(right == -1 || abs(left - right) > 1)
                return -1;
            return max(right, left) + 1;
        }
    };