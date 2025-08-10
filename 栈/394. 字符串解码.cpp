class Solution {
public:
    string decodeString(string s) {
        int n = s.size(), idx = 0;

        auto Branch = [&](this auto&& Branch) -> string{
            string res;
            int size = 0;
            while(idx < n)
            {
                char ch = s[idx];
                idx++;
                if(isalpha(ch))
                {
                    res += ch;
                }
                else if(isdigit(ch))
                {
                    size = size * 10 + (ch - '0');
                }
                else if(ch == '[')
                {
                    string s = Branch();
                    for(; size > 0; size--)
                    {
                        res += s;
                    }
                }
                else if(ch == ']')
                    break;
            }
            return res;
        };

        return Branch();
    }
};