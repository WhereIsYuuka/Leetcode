class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector< vector<int>> res;
        if(intervals.size() == 0)
        {
            res.push_back(newInterval);
            return res;
        }
        int l = newInterval[0];
        int r = newInterval[1];
        for(int i = 0; i < intervals.size();)
        {
            if(intervals[i][1] < l)
            {
                res.push_back(intervals[i]);
                i++;
            }
            else if(intervals[i][0] > r)
            {
                res.push_back({l, r});
                while(i < intervals.size())
                {
                    res.push_back(intervals[i]);
                    i++;
                }
            }
            else
            {
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
                i++;
            }
        }
        if(res.size() == 0 || res[res.size()-1][1] < l)
        {
            res.push_back({l, r});
        }
        
        
        return res;
    }
};