class Solution {
    public:
        int encryptionCalculate(int dataA, int dataB) {
            int tmpNum;
            while(dataA)
            {
                tmpNum = dataA & dataB;
                dataB = dataA ^ dataB;
                dataA = (unsigned)tmpNum << 1;
            }
            return dataB;
        }
    };