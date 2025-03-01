class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> hash;
        int n = 0;
        for(auto& e : equations)
        {
            if(!hash.count(e[0]))
                hash[e[0]] = n++;
            if(!hash.count(e[1]))
                hash[e[1]] = n++;
        }
        vector<vector<double>> g(n, vector<double>(n, -1.0));
        for(int i = 0; i < n; i++)
            g[i][i] = 1.0;
        for(int i = 0; i < equations.size(); i++)
        {
            int a = hash[equations[i][0]], b = hash[equations[i][1]];
            g[a][b] = values[i];
            g[b][a] = 1.0 / values[i];
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(g[i][k] != -1.0 && g[k][j] != -1.0)
                        g[i][j] = g[i][k] * g[k][j];
        vector<double> res;
        for(auto& q : queries)
        {
            if(!hash.count(q[0]) || !hash.count(q[1]))
            {
                res.push_back(-1.0);
                continue;
            }
            int a = hash[q[0]], b = hash[q[1]];
            res.push_back(g[a][b]);
        }
        return res;
    }
};