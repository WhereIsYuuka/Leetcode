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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for(int i = 0; i < len; i++)
            Unmp[inorder[i]] = i;
        return buildTree(preorder, inorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd)
    {
        if(pStart > pEnd || iStart > iEnd)
            return nullptr;
        int dis = Unmp[preorder[pStart]] - iStart;
        TreeNode *root = new TreeNode(preorder[pStart]);
        root->left = buildTree(preorder, inorder, pStart+1, pStart+dis, iStart, iStart+dis-1);
        root->right = buildTree(preorder, inorder, pStart+dis+1, pEnd, iStart+dis+1, iEnd);
        return root;
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
//     unordered_map<int ,int> map;
//     TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
//         if(pl >pr || il > ir)
//             return nullptr;
//         int dis = map[preorder[pl]] - il;
//         TreeNode* root = new TreeNode(preorder[pl]);
//         root->left = Build(preorder, inorder, pl+1, pl+dis, il, il+dis-1);
//         root->right = Build(preorder, inorder,pl+1+dis, pr, il+1+dis, ir);
//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         for(int i = 0; i < n; i++)
//             map[inorder[i]] = i;
//         return Build(preorder, inorder, 0, n-1, 0, n-1);
//     }
// };