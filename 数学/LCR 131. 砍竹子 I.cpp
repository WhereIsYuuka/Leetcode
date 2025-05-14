class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if(bamboo_len <= 3)
            return bamboo_len - 1;
        int round = bamboo_len / 3;
        if(bamboo_len % 3 == 0)
            return pow(3, round);
        else if(bamboo_len % 3 == 1)
            return pow(3, round - 1) * 4;
        else
            return pow(3, round) * 2;
        return 1;
    }
};