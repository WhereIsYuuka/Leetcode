class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)
            return "";
        auto gcd = [&](this auto&& gcd, int a, int b) -> int{
            return b == 0 ? a : gcd(b, a % b);
        };
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};