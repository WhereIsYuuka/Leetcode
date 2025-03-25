class Solution {
    public:
        int iceBreakingGame(int num, int target) {
            // 最后活一人，下标为 0 = f0
            // 存在两人，活得人下标为 (f0 + target) % 2 = f1
            // 存在三人，活下来的人下标是 (f1 + target) % 2 = f2
            // ...依次循环直到逆推完所有人
            int res = 0;
            for(int i = 2; i <= num; i++)
            {
                res = (res + target) % i;
            }
            return res;
        }
    };