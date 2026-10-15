class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // vector<int> path;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3)
            return res;
        for(int i = 0; i < n-2; i++)
        {
            if(i && nums[i] == nums[i-1])
                continue;
            if(nums[i] + nums[i+1] + nums[i+2] > 0)
                break;
            if(nums[i] + nums[n-1] + nums[n-2] < 0)
                continue;
            int l = i+1, r = n-1;
            while(l < r)
            {
                int _sum = nums[i] + nums[l] + nums[r];
                if(_sum < 0)
                    l++;
                else if(_sum > 0)
                    r--;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while(l < r && nums[l] == nums[l-1])    
                        l++;
                    while(l < r && nums[r] == nums[r+1])    
                        r--;
                }
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector< vector<int>> res;
//         if(nums.size() < 3) return res;
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < nums.size() - 2; i++)
//         {
//             if(i > 0 && nums[i] == nums[i-1])   
//                 continue;
//             if(nums[i] > 0) 
//                 return res;
//             int l = i+1, r = nums.size() - 1;
//             while(l < r)
//             {
//                 int sum = nums[i] + nums[l] + nums[r];
//                 if(sum == 0)
//                 {
//                     res.push_back(vector<int>{nums[i], nums[l], nums[r]});
//                     while(l < r && nums[l] == nums[l+1]) l++;
//                     while(l < r && nums[r] == nums[r-1]) r--;
//                     l++, r--;
//                 }
//                 else if(sum > 0)
//                     r--;
//                 else
//                     l++;
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector< vector<int>> res;
//         int len = nums.size();
//         sort(nums.begin(),nums.end());    //0,0,0,0
//         for(int i = 0; i < len; i++){
//             int l = i+1, r = len-1;
//             if(nums[i] > 0) return res;
//             if(i > 0 && nums[i] == nums[i-1])    continue;
//             while(l < r){
//                 if(nums[l]+nums[i]+nums[r] == 0){
//                     res.push_back(vector<int>{nums[i],nums[l],nums[r]});
//                     while(l < r && nums[r] == nums[r-1]) r--;
//                     while(l < r && nums[l] == nums[l+1]) l++;
//                     r--;
//                     l++;
//                 }
//                 if(nums[l]+nums[i]+nums[r] > 0){
//                     r--;
//                 }
//                 if(nums[l]+nums[i]+nums[r] < 0){
//                     l++;
//                 }
//             }
//         }

//         return res;
//     }
// };