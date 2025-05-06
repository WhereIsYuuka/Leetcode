class Solution {
    public:
        int maxSales(vector<int>& sales) {
            int len = sales.size();
            int res = sales[0];
            for(int i = 1; i < len; i++)
            {
                if(sales[i-1] > 0)
                    sales[i] += sales[i-1];
                if(sales[i] > res)
                    res = sales[i];
            }
            return res;
        }
    };