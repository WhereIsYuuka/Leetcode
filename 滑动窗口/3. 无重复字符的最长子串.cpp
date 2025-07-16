class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if(!s.length())
            return res;

        unordered_set<char> uset;
        int l = 0;
        for(int r = 0; r < s.length(); r++)
        {
            char ch = s[r];
            while(uset.contains(ch))
            {
                uset.erase(s[l++]);
            }
            uset.emplace(ch);
            res = max(res, r - l + 1);
        }
        return res;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(!s.length())
//             return 0;
//         int cnt[128];
//         int l = 0, res = 0;
//         for(int r = 0; r < s.length(); r++)
//         {
//             while(cnt[s[r]])
//             {
//                 char ch = s[l];
//                 cnt[ch]--;
//                 l++;
//             }
//             cnt[s[r]]++;
//             res = max(res, r - l + 1);
//         }
//         return res;
//     }
// };