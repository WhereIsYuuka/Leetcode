class Solution {
public:
    int calculate(string s) {
        long res = 0;
        int num = 1, i = 0, len = s.length();
        stack<int> nums;
        nums.push(num);
        while(i < len)
        {
            if(s[i] == ' ') 
                i++;
                if(s[i] == '+')
                {
                    num = nums.top();
                    i++;
                }
                else if(s[i] == '-')
                {
                    num = -nums.top();
                    i++;
                }
                else if(s[i] == '(')
                {
                    nums.push(num);
                    i++;
                }
                else if(s[i] == ')')
                {
                    nums.pop();
                    i++;
                }
                else
                {
                    long sum = 0;
                    while(i < len && s[i] >= '0' && s[i] <= '9')
                    {
                        sum = sum*10 + s[i]-'0';
                        i++;
                    }
                    res += num*sum;
                }
        }
        return res;
    }
};