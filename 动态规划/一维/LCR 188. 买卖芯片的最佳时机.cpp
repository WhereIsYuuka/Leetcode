class Solution {
    public:
        int bestTiming(vector<int>& prices) {
            int res = 0;
            if(prices.size() <= 1)
                return res;
            int l = 0, r = 0;
            while(++r < prices.size())
            {
                if(prices[r] <= prices[l])
                {
                    l = r;
                    continue;
                }
                int tmp = prices[r] - prices[l];
                if(tmp > res)
                    res = tmp;
            }
            return res;
        }
    };