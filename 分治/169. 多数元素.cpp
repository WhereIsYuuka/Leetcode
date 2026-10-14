class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curNum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(cnt == 0)
                curNum = nums[i];
            if(curNum == nums[i])
            {
                cnt++;
            }
            else
                cnt--;
        }
        return curNum;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};