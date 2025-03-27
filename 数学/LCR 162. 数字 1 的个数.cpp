class Solution {
    public:
        int digitOneInNumber(int num) {
            long digit = 1;
            int high = num / 10, low = 0, cur = num % 10, res = 0;
            while(high != 0 || cur != 0)
            {
                if(cur == 0)
                    res += high * digit;
                else if(cur == 1)
                    res += high * digit + low + 1;
                else
                    res += (high + 1) * digit;
                
                low += cur * digit;
                cur = high % 10;
                high /= 10;
                digit *= 10;
            }
            return res;
        }
    };