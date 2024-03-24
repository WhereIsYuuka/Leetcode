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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(pre && pre->val >= root->val)
                return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};

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
// class Solution {
// public:
//     long Lastnum = LONG_MIN;
//     bool isValidBST(TreeNode* root) {
        
//         if(!root)
//             return true;
//         if(!isValidBST(root->left))
//         {
//             return false;
//         }
//         if(Lastnum >= root->val)
//             return false;
//         Lastnum = root->val;
//         return isValidBST(root->right);
//     }
// };