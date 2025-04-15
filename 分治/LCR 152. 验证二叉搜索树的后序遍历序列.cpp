class Solution {
    public:
        bool verifyTreeOrder(vector<int>& postorder) {
            //二叉搜索树 left < root < right
            //后序遍历   left -> right -> root
            //后序逆序   root -> right -> left
            stack<int> stk;
            int parent = INT_MAX;
            for(int i = postorder.size()-1; i >= 0; i--)
            {
                int cur = postorder[i];
                while(!stk.empty() && stk.top() > cur)
                {
                    parent = stk.top();
                    stk.pop();
                }
                if(parent < cur)    //遍历完栈后没有大的
                    return false;
                stk.emplace(cur);
            }
            return true;
        }
    };