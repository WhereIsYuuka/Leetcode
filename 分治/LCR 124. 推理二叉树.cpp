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
    private:
        unordered_map<int, int> ump;
    
    public:
        TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
            for(int i = 0; i < inorder.size(); i++)
            {
                ump[inorder[i]] = i;
            }
            return CreateTree(preorder, 0, 0, inorder.size() - 1);
        }
    
        TreeNode* CreateTree(vector<int>& preorder, int root, int left, int right)
        {
            if(left > right)
                return nullptr;
            TreeNode* node = new TreeNode(preorder[root]);
            int idx = ump[preorder[root]];
            node->left = CreateTree(preorder, root + 1, left, idx - 1);
            node->right = CreateTree(preorder, idx - left + root + 1, idx + 1, right);
            return node;
        }
    };