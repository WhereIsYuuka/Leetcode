class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.length();

        for(int i = 0; i < n; i++)
        {
            //奇数
            int l = i-1, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r])
                l--, r++;
            if(res.length() < r-l-1)
                res = s.substr(l+1, r-l-1);
            //偶数
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r])
                l--, r++;
            if(res.length() < r-l-1)
                res = s.substr(l+1, r-l-1);
        }
        return res;
    }
};

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         string res = "";
//         int n = s.length();
//         int l = 0, r = 0;
//         for(int i = 0; i < n; i++)
//         {
//             l = i-1, r = i+1;
//             while(l >= 0 && r < n && s[l] == s[r])
//                 r++, l--;
//             if(res.length() < r - l - 1)
//                 res = s.substr(l + 1, r - l - 1);
//             l = i, r = i+1;
//             while(l >= 0 && r < n && s[l] == s[r])
//                 r++, l--;
//             if(res.length() < r - l - 1)
//                 res = s.substr(l + 1, r - l - 1);
//         }
//         return res;
//     }
// };