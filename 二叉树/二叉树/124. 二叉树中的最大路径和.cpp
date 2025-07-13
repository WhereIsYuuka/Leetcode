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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
};

// class Solution {
// int res = INT_MIN;

// public:
//     int maxPathSum(TreeNode* root) {
//         dfs(root);
//         return res;
//     }

//     int dfs(TreeNode* root)
//     {
//         if(root == nullptr)
//             return 0;
//         int l = dfs(root->left);
//         int r = dfs(root->right);

//         res = max(res, l + r + root->val);
//         return max(max(l, r) + root->val, 0);
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
// private:
//     int numMax = INT_MIN;

// public:
//     int maxPathSum(TreeNode* root) {
//         countMax(root);
//         return numMax;
//     }

//     int countMax(TreeNode* root)
//     {
//         if(!root)
//             return 0;
//         int left = max(countMax(root->left), 0);
//         int right = max(countMax(root->right), 0);
//         numMax = max(numMax, root->val + left + right);
//         return root->val + max(left, right);
//     }
// };