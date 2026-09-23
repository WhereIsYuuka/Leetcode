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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> nodePath;
        nodePath.push(root);
        while(!nodePath.empty())
        {
            vector<int> numPath;
            int n = nodePath.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* tmp = nodePath.front();
                nodePath.pop();
                if(tmp->left)
                    nodePath.push(tmp->left);
                if(tmp->right)
                    nodePath.push(tmp->right);
                numPath.emplace_back(tmp->val);

            }
            res.emplace_back(numPath);
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if(!root)
//             return res;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             int size = q.size();
//             vector<int> level;
//             for(int i = 0; i < size; i++)
//             {
//                 TreeNode* tmp = q.front();
//                 q.pop();
//                 level.push_back(tmp->val);
//                 if(tmp->left)
//                     q.push(tmp->left);
//                 if(tmp->right)
//                     q.push(tmp->right);
//             }
//             res.push_back(level);
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if(!root)
//             return res;
//         queue<TreeNode*> treeQue;
//         treeQue.emplace(root);
//         while(!treeQue.empty())
//         {
//             vector<int> rowTree;
//             int len = treeQue.size();
//             for(int i = 0; i < len; i++)
//             {
//                 TreeNode* tmp = treeQue.front();
//                 rowTree.emplace_back(tmp->val);
//                 treeQue.pop();
//                 if(tmp->left)
//                     treeQue.emplace(tmp->left);
//                 if(tmp->right)
//                     treeQue.emplace(tmp->right);
//             }
//             res.emplace_back(rowTree);
//         }
//         return res;
//     }
// };