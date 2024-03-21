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
class BSTIterator {
private:
    vector<TreeNode*> res;
public:
    BSTIterator(TreeNode* root) {
        while(root)
        {
            res.push_back(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* tmp = res.back();
        res.pop_back();
        TreeNode* cur = tmp->right;
        while(cur)
        {
            res.push_back(cur);
            cur = cur->left;
        }
        return tmp->val;
    }// 模拟中序遍历
    
    bool hasNext() {
        return res.empty() ? false : true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */