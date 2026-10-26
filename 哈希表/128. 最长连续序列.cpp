class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> uset(nums.begin(), nums.end());
        for(auto it : uset)
        {
            if(uset.count(it-1))
                continue;
            int cnt = 0, curNum = it;
            while(uset.count(curNum++))
            {
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0)
//             return 0;
//         set<int> tmp;
//         int maxSum = 0, tmpSum = 1;
//         set<int>::iterator it;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             tmp.insert(nums[i]);
//         }
//         for(const int& num : tmp)
//         {
//             if(tmp.count(num+1))
//             {
//                 tmpSum++;
//             }
//             else
//             {
//                 maxSum = max(maxSum, tmpSum);
//                 tmpSum = 1;
//             }
//         }
//         return maxSum;
//     }
// };


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> s(nums.begin(), nums.end());
//         int res = 0;
//         for(int num : nums)
//         {
//             if(!s.count(num - 1))
//             {
//                 int cur = num;
//                 int curLen = 1;
//                 while(s.count(cur + 1))
//                 {
//                     cur++;
//                     curLen++;
//                 }
//                 res = max(res, curLen);
//             }
//         }
//         return res;
//     }
// };
