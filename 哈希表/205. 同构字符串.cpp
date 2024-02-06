class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> res1, res2;
        for(int i = 0; i < s.length(); i++)
        {
            if(res1[s[i]] != res2[t[i]])
                return false;
            else
            {
                if(res1[s[i]] == 0)
                {
                    res1[s[i]] = i + 1;
                    res2[t[i]] = i + 1;
                }
            }
        }
        return true;
    }
};