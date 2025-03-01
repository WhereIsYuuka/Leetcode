#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m,n,k;
    cin >> m >> n;
    vector<vector<int>> vec1(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> vec1[i][j];
        }
    }
    cin >> n >> k;
    vector<vector<int>> vec2(n, vector<int>(k, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> vec2[i][j];
        }
    }
    vector<vector<int>> res(m, vector<int>(k, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            for(int l = 0; l < n; l++)
            {
                res[i][j] += vec1[i][l] * vec2[l][j];
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

