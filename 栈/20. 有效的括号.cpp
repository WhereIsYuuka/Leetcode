class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(auto it : s)
        {
            if(it == '(' || it == '[' || it == '{')
                sta.push(it);
            else
            {
                if(sta.empty())
                    return false;
                else if(it == ')' && sta.top() != '(')
                    return false;
                else if(it == ']' && sta.top() != '[')
                    return false;
                else if(it == '}' && sta.top() != '{')
                    return false;
                sta.pop();
            }
        }
        return sta.empty();
    }
};


// class Solution {
// public:
//     stack<char> sta;
//     bool isValid(string s) {
//         if(s.size() % 2 != 0)   //长度为奇
//             return false;   
//         for(int i = 0; i < s.length(); i++)
//         {
//             if(s[i] == '(')
//             {
//                 sta.push(')');
//             }
//             else if(s[i] == '[')
//             {
//                 sta.push(']');
//             }
//             else if(s[i] == '{')
//             {
//                 sta.push('}');
//             }
//             else
//             {
//                 if(sta.empty() || s[i] != sta.top())
//                     return false;
//                 else
//                     sta.pop();
//             }
//         }
//         return sta.empty();
//     }
// };