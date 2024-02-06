class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int>> res;
        if(nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])   
                continue;
            if(nums[i] > 0) 
                return res;
            int l = i+1, r = nums.size() - 1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0)
                {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++, r--;
                }
                else if(sum > 0)
                    r--;
                else
                    l++;
            }
        }
        return res;
    }
};

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