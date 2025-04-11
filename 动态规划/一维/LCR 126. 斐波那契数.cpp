class Solution {
    public:
        int fib(int n) {
            if(n == 0 || n == 1)
                return n;
            int cur = 1, before = 0;
            for(int i = 1; i < n; i++)
            {
                cur += before;
                before = cur - before;
                cur %= 1000000007;
            }
            return cur;
        }
    };