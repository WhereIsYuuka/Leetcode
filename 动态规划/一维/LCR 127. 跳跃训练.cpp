class Solution {
    public:
        int trainWays(int num) {
            if(num == 1 || num == 2)
                return num;
            else if(num == 0)
                return 1;
            int cur = 2, before = 1;
            for(int i = 3; i <= num; i++)
            {
                cur += before;
                before = cur - before;
                cur %= 1000000007;
            }
            return cur;
        }
    };