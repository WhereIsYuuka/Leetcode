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
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        unordered_map<long long, int> mp = {{0, 1}};  //添加自己
        auto dfs = [&](this auto&& dfs, TreeNode* node, long long preSum) -> void {
            if(node == nullptr)
                return;
            long long s = preSum + node->val;
            res += mp[s - targetSum];
            mp[s]++;
            dfs(node->left, s);
            dfs(node->right, s);
            mp[s]--;
        };
        dfs(root, 0);
        return res;
    }
};