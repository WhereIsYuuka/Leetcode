class Solution {
public:
    bool checkDynasty(vector<int>& places) {
        int cnt = 0;
        sort(places.begin(), places.end());
        for(int i = 0; i < 4; i++)
        {
            if(places[i] == 0)
            {
                cnt++;
                continue;
            }
            else if(places[i] == places[i+1])
                return false;
            else if(places[i] + 1 != places[i + 1])
            {
                int tmp = places[i + 1] - places[i] - 1;
                if(tmp > cnt)
                    return false;
                cnt -= tmp;
            }
        }
        return true;
    }
};