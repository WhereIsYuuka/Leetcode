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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* pre = nullptr;
        dfs(root, pre, ans);
        return ans;
    }

    int dfs(TreeNode* &root, TreeNode* &pre, int &ans)
    {
        if(!root)
            return 0;
        dfs(root->left, pre, ans);
        if(pre)
            ans = min(ans, abs(root->val - pre->val));
        pre = root;
        dfs(root->right, pre, ans);
        return 0;
    }
};