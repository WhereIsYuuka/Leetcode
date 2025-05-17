class Solution {
public:
    vector<string> goodsOrder(string goods) {
        vector<string> res;
        dfs(res, goods, 0);
        return res;
    }

    void dfs(vector<string> &res, string &goods, int idx)
    {
        if(idx == goods.length())
        {
            res.emplace_back(goods);
            return;
        }
        for(int i = idx; i < goods.length(); i++)
        {
            bool isSame = false;
            for(int j = idx; j < i; j++)
            {
                if(goods[i] == goods[j])
                {
                    isSame = true;
                }
            }
            if(!isSame)
            {
                swap(goods[idx], goods[i]);
                dfs(res, goods, idx+1);
                swap(goods[idx], goods[i]);
            }
        }
    }
};