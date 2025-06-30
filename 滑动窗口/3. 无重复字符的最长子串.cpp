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