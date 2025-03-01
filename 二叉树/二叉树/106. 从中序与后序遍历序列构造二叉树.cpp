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
    unordered_map<int, int> Unmp;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        for(int i = 0; i < len; i++)
            Unmp[inorder[i]] = i;
        return buildTree(inorder, postorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int iStart, int iEnd, int pStart, int pEnd)
    {
        if(iStart > iEnd || pStart > pEnd)
            return nullptr;
        int dis = Unmp[postorder[pEnd]] - iStart;
        TreeNode *root = new TreeNode(postorder[pEnd]);
        root->left = buildTree(inorder, postorder, iStart, iStart+dis-1, pStart, pStart+dis-1);
        root->right = buildTree(inorder, postorder, iStart+dis+1, iEnd, pStart+dis, pEnd-1);
        return root;    
     }
};