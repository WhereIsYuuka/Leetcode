// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         map<int, int> res;
//         int n = nums.size();
//         int tmp = n-k;
//         for(int i = 0; i < n; i++)
//         {
//             res[nums[i]]++;
//         }
//         for(auto& c : res)
//         {
//             if(tmp == 0 || c.second > tmp)
//                 return c.first;
//             tmp -= c.second;
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSort(nums, k);
    }
    int QuickSort(vector<int>& nums, int k)
    {
        int judge = nums[rand() % nums.size()];
        vector<int> small, equal, big;
        for(int num : nums)
        {
            if(num < judge) 
                small.push_back(num);
            else if(num == judge)
                equal.push_back(num);
            else
                big.push_back(num);
        }
        if(big.size() >= k)
            return QuickSort(big, k);
        else if(big.size() + equal.size() < k)
            return QuickSort(small, k - (big.size() + equal.size()));
        else
            return judge;
    }
};