class Solution {
public:
    int inventoryManagement(vector<int>& stock) {
        int l = 0, r = stock.size() - 1, mid = 0;
        while(l < r)
        {
            mid = (r - l) / 2 + l;
            if(stock[mid] > stock[r])
                l = mid + 1;
            else if(stock[mid] < stock[l])
                r = mid;
            else
                r--;
        }
        return stock[l];
    }
};