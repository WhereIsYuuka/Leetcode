class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0, minNum = INT_MAX;

        for(auto it : prices)
        {
            res = max(res, it - minNum);
            minNum = min(minNum, it);
        }
        return res;
    }
};