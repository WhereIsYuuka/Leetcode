class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0)  return 1;
        if(n < 0)   return 1 / myPow(x, -n);
        double half = myPow(x, n / 2);
        if(n % 2 == 0)  return half * half;
        else    return half * half * x;
    }
};
//negation of -2147483648 cannot be represented in type 'int'; 
// cast to an unsigned type to negate this value to itself
// 所以要把n转换为long类型