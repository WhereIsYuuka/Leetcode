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

void count(int n)
{
    int a[10] = {0};
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        while(j)
        {
            a[j%10]++;
            j /= 10;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        if(i > 0)
            cout << endl;
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    int n;
    while(cin >> n)
    {
        count(n);
    }
    return 0;
}
