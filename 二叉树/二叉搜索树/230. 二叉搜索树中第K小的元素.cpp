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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(--k == 0)
                return root->val;
            root = root->right;
        }   
        return -1;
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
//     vector<int> nums;
//     TreeNode* Traverse(TreeNode* root){
//         if(root)
//         {
//             nums.push_back(root->val);
//             if(root->left)
//                 Traverse(root->left);
//             if(root->right)
//                 Traverse(root->right);
//         }
//         return nullptr;
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         Traverse(root);
//         sort(nums.begin(), nums.end());
//         return nums[k-1];
//     }
// };

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
//     int kthSmallest(TreeNode* root, int k) {
//         int res = -1;

//         auto dfs = [&](this auto&& dfs, TreeNode* root){
//             if(root == nullptr)
//                 return;
//             dfs(root->left);
//             if(--k == 0)
//             {
//                 res = root->val;
//                 return;
//             }
//             dfs(root->right);
//         };
//         dfs(root);
//         return res;
//     }
// };