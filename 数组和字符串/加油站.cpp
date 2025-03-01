class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int point = 0;
        int time = gas.size();
        int cursum = 0, endsum = 0;
        for(int i = 0; i < time; i++)
        {
            cursum += gas[i] - cost[i];
            endsum += gas[i] - cost[i];
            if(cursum < 0)
            {
                cursum = 0;
                point = (i+1) % time;
            }
        }
        if(endsum < 0)
            return -1;
        return point;
    }
};
