#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string>
#include<cstring>
#include<list>
#include<stdlib.h>
using namespace std;
typedef int status;
typedef int selemtype;

int main()
{
    int k;
    while(cin >> k)
    {
        int n = pow(2, k);
        int a[10][10] = {0};
        for(int i = 1; i <= n; i++)
            a[i][1] = i;
        for(int i = 1; i <= k; i++)
        {
            int m = pow(2, i-1);
            for(int j = 1; j <= n; j++)
            {
                if(j % (2*m) <= m)
                {
                    for(int l = 1; l <= m; l++)
                        a[j][m+l] = a[j][l];
                }
                else
                {
                    for(int l = 1; l <= m; l++)
                        a[j][m+l] = a[j][l] + m;
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(j > 1)
                    cout << ' ';
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}