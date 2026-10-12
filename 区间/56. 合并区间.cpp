class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        int n = intervals.size();
        for(int i = 0; i < n; i++)
        {
            l = min(l, intervals[i][0]);
            r = max(r, intervals[i][1]);
            if(i == n-1 || intervals[i+1][0] > r)
            {
                res.push_back({l, r});
                l = INT_MAX;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector< vector<int>> res;
//         if(intervals.size() == 0)
//             return res;
//         sort(intervals.begin(), intervals.end());
//         int l, r;
//         for(int i = 0; i < intervals.size();)
//         {
//             l = intervals[i][0];
//             r = intervals[i][1];
//             while(i < intervals.size() - 1 && r >= intervals[i + 1][0])
//             {
//                 r = max(r, intervals[i + 1][1]);
//                 i++;
//             }
//             res.push_back({l, r});
//             i++;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> res;
//         if(intervals.size() < 1)    
//             return res;
//         sort(intervals.begin(), intervals.end());
//         for(auto interval : intervals)
//         {
//             if(!res.empty() && interval[0] <= res.back()[1])
//             {
//                 res.back()[1] = max(interval[1], res.back()[1]);
//             }
//             else
//             {
//                 res.emplace_back(interval);
//             }
//         }
//         return res;
//     }
// };