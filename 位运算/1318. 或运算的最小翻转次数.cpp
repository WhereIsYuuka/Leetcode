class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a != 0 || b != 0 || c != 0)
        {
            int a1 = a & 1, b1 = b & 1, c1 = c & 1;
            a >>= 1, b>>= 1, c >>= 1;
            if((a1 | b1) == c1)
            {
                continue;
            }
            if(c1 == 0)
            {
                if(a1 == 1)
                    res++;
                if(b1 == 1)
                    res++;
            }
            else
            {
                res++;
            }
        }
        return res;
    }
};