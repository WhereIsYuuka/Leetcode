class Solution {
    public:
        int countTarget(vector<int>& scores, int target) {
            int res = 0;
            for(auto it : scores)
            {
                if(it == target)
                {
                    res ++;
                }
            }
            return res;
        }
    };