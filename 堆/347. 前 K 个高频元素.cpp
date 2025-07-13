class Solution {
public:
    //Count the number of occurrences and get it from high to low
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int maxCnt = 0;
        for(auto num : nums)
        {
            cnt[num]++;
            maxCnt = max(maxCnt, cnt[num]);
        }
        vector<vector<int>> rev(maxCnt + 1);
        for(auto [a, b] : cnt)
        {
            rev[b].emplace_back(a);
        }
        vector<int> res;
        for(int i = maxCnt; i >= 0 && res.size() < k; i--)
        {
            res.insert(res.end(), rev[i].begin(), rev[i].end());
        }
        return res;
    }
};