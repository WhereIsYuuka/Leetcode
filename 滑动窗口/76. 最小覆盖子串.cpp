class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n == 0 || m == 0 || n < m)
            return "";
        unordered_map<char, int> need, window;
        int left = 0, right = 0;
        int vaild = 0, start = 0, len = INT_MAX;
        for(char c :t)
            need[c]++;
        while(right < n)
        {
            char c = s[right++];
            if(need.count(c))
            {
                window[c]++;
                if(window[c] == need[c])
                    vaild++;
            }
            while(vaild == need.size())
            {
                if(right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left++];
                if(need.count(d))
                {
                    window[d]--;
                    if(window[d] < need[d])
                        vaild--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if(s.length() < t.length())
//             return "";
//         unordered_map<char, int> cnt;
//         int l = 0, len = s.length(), loss = 0;
//         int lRes = -1, rRes = len;
//         for(auto ch : t)
//         {
//             if(cnt[ch] == 0)
//                 loss++;
//             cnt[ch]++;
//         }
//         for(int r = 0; r < len; r++)
//         {
//             char ch = s[r];
//             cnt[ch]--;
//             if(cnt[ch] == 0)
//             {
//                 loss--;
//             }
//             while(loss == 0)
//             {
//                 if(r - l < rRes - lRes)
//                 {
//                     rRes = r;
//                     lRes = l;
//                 }
//                 char chL = s[l];
//                 if(cnt[chL] == 0)
//                 {
//                     loss++;
//                 }
//                 cnt[chL]++;
//                 l++;
//             }
//         }
//         return lRes < 0 ? "" : s.substr(lRes, rRes - lRes + 1);
//     }
// };