class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int res = 0;
        // 从后往前遍历
        for(int i = len - 1; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                // 如果res为0，说明前面有空格，直接跳过
                if(res == 0)
                    continue;
                // 否则，说明遇到了第一个单词，直接返回
                break;
            }
            res++;
        }
        return res;
    }
};