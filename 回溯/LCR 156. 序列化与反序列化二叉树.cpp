/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    public:
    
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string res = "";
            if(root == NULL)
                return res;
            queue<TreeNode*> que;
            que.emplace(root);
            TreeNode* tmp;
            while(!que.empty())
            {
                int len = que.size();
                while(len--)
                {
                    tmp = que.front();
                    que.pop();
                    if(tmp == NULL)
                        res.push_back('@');
                    else
                        res.append(to_string(tmp->val));
                    
                    res.push_back(',');
                    if(tmp != NULL)
                    {
                        que.emplace(tmp->left);
                        que.emplace(tmp->right);
                    }
                }
            }
            res.pop_back(); //去除最后的逗号
            return res;
        }
    
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            int lenStr = data.length(), idx = 0;
            if(0 == lenStr)
                return NULL;
            vector<TreeNode*> treeVec;
            while(idx < lenStr)
            {
                string tmpStr = "";
                while(idx < lenStr && data[idx] != ',')
                {
                    tmpStr.push_back(data[idx++]);
                }
                if("@" == tmpStr)
                {
                    TreeNode* node = NULL;
                    treeVec.emplace_back(node);
                }
                else
                {
                    int num = stoi(tmpStr);
                    TreeNode* node = new TreeNode(num);
                    treeVec.emplace_back(node);
                }
                idx++;  //跳过逗号
            }
            idx = 1;
            int lenVec = treeVec.size();
            for(int i = 0; i < lenVec; i++)
            {
                if(treeVec[i] == NULL)
                    continue;
                if(idx < lenVec)
                    treeVec[i]->left = treeVec[idx++];
                if(idx < lenVec)
                    treeVec[i]->right = treeVec[idx++];
            }
            return treeVec[0];
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec codec;
    // codec.deserialize(codec.serialize(root));