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
        bool isSubStructure(TreeNode* A, TreeNode* B) {
            if(A == nullptr || B == nullptr)
                return false;
            if(FindTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B))
                return true;
            return false;
        }
    
        bool FindTree(TreeNode* A, TreeNode* B)
        {
            if(B == nullptr)
                return true;
            if(A == nullptr || A->val != B->val)
                return false;
            return FindTree(A->left, B->left) && FindTree(A->right, B->right);
        }
    };