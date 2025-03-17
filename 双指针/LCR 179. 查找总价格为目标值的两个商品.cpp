class Solution {
    public:
        vector<int> twoSum(vector<int>& price, int target) {
            int len = price.size();
            int l = 0, r = len - 1;
            while(l < r)
            {
                int sum = price[l] + price[r];
                if(sum == target)
                    return {price[l], price[r]};
                else if(sum < target)
                    l++;
                else
                    r--;
            }
            return {};
        }
    };