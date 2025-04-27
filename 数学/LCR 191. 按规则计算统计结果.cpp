class Solution {
    public:
        vector<int> statisticalResult(vector<int>& arrayA) {
            int len = arrayA.size(), right = 1;
            vector<int> res(len, 1);
            for(int i = 1; i < len; i++)
            {
                res[i] = res[i-1] * arrayA[i-1];
            }
            for(int i = len-1; i >= 0; i--)
            {
                res[i] *= right;
                right *= arrayA[i];
            }
            return res;
        }
    };