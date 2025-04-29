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
        bool checkSymmetricTree(TreeNode* root) {
            if(root == nullptr)
                return true;
            return checkTree(root->left, root->right);
        }
    
        bool checkTree(TreeNode* left, TreeNode* right)
        {
            if(left == nullptr && right == nullptr)
                return true;
            else if(left == nullptr && right != nullptr)
                return false;
            else if(left != nullptr && right == nullptr)
                return false;
            else if(left->val != right->val)
                return false;
            
            return checkTree(left->right, right->left) && checkTree(left->left, right->right);
    
        }
    };