class Solution {
    public:
        int trainingPlan(vector<int>& actions) {
            int res = 0;
            vector<int> counts(32, 0);  //int 32位
            for(int i = 0; i < actions.size(); i++)
            {
                for(int j = 0; j < 32; j++)
                {
                    counts[j] += (actions[i] >> j & 1) == 1 ? 1 : 0;
                }
            }
    
            for(int i = 31; i >= 0; i--)
            {
                res = res << 1;
                if(counts[i] % 3 == 1)  //三个0，需要将末尾设置为1
                {
                    res = res | 1;
                }
            }
            return res;
        }
    };