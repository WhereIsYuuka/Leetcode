class Solution {
    private:
        int res = 0;
    
    public:
        // //上底加下底之和除二☝️🤓
        // int mechanicalAccumulator(int target) {
        //     char res[target][target+1];
        //     return sizeof(res) >> 1;
        // }
        int mechanicalAccumulator(int target) {
            target > 1 && mechanicalAccumulator(target-1);
            res += target;
            return res;
        }
    };