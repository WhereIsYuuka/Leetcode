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
//     vector<TreeNode*> trees;
//     void flatten(TreeNode* root) {
//         if(!root)
//             return;
            
//         dfs(root);
//         for(int i = 0; i < trees.size()-1; i++)
//         {
//             trees[i]->left = nullptr;
//             trees[i]->right = trees[i+1];
//         }
//     }

//     void dfs(TreeNode* root)
//     {
//         if(!root)
//             return;
//         trees.emplace_back(root);
//         dfs(root->left);
//         dfs(root->right);
//     }
// };