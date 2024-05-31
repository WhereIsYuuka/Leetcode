class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int len = strs.size();
        string res = strs[0];
        for(int i = 1; i < len; i++)
        {
            int j = 0;
            // 比较两个字符串的公共前缀,长度取两者最小值
            for(; j < res.size() && j < strs[i].size(); j++)
            {
                if(res[j] != strs[i][j])
                    break;
            }
            res = res.substr(0, j);
            if(res.empty())
                return res;
        }
        return res;
    }
};