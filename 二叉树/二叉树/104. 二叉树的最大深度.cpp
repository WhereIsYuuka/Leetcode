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
    int res = 0;

    void dfs(TreeNode* root, int depth) 
    {
        if(root == nullptr)
            return;
        res = max(res, depth + 1);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return res;
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
// private:
//     int res = 0;

// public:
//     int maxDepth(TreeNode* root) {
//         if(!root)
//             return 0;
        
//         auto dfs = [&](this auto&& dfs, TreeNode* root, int i) -> void{
//             if(!root)
//                 return;
//             res = max(res, i);
//             dfs(root->left, i+1);
//             dfs(root->right, i+1);
//         };

//         dfs(root, 1);
//         return res;
//     }
// };