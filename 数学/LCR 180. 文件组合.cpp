class Solution {
    public:
        vector<vector<int>> fileCombination(int target) {
            vector<vector<int>> res;
            int num = 1;
            while(target > 0)
            {
                target -= num++;
                if(target != 0 && target % num == 0)
                {
                    int min_num = target / num;
                    vector<int> tmp;
                    for(int i = 0; i < num; i++)
                    {
                        tmp.emplace_back(min_num+i);
                    }
                    res.emplace_back(tmp);
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };