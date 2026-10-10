class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        stack<int> times;
        string res = "";
        int time = 0;
        for(auto ch : s)
        {
            if(ch >= '0' && ch <= '9')
            {
                time = time * 10 + (ch - '0');
                continue;
            }
            else if(ch == '[')
            {
                times.push(time);
                time = 0;
                stk.push(res);
                res = "";
            }
            else if(ch == ']')
            {
                int _time = times.top();
                times.pop();
                for(int i = 0; i < _time; i++)
                {
                    stk.top() += res;
                }
                res = stk.top();
                stk.pop();
            }
            else
            {
                res += ch;
            }
        }

        return res;
    }
};

// class Solution {
// public:
//     string decodeString(string s) {
//         int n = s.size(), idx = 0;

//         auto Branch = [&](this auto&& Branch) -> string{
//             string res;
//             int size = 0;
//             while(idx < n)
//             {
//                 char ch = s[idx];
//                 idx++;
//                 if(isalpha(ch))
//                 {
//                     res += ch;
//                 }
//                 else if(isdigit(ch))
//                 {
//                     size = size * 10 + (ch - '0');
//                 }
//                 else if(ch == '[')
//                 {
//                     string s = Branch();
//                     for(; size > 0; size--)
//                     {
//                         res += s;
//                     }
//                 }
//                 else if(ch == ']')
//                     break;
//             }
//             return res;
//         };

//         return Branch();
//     }
// };