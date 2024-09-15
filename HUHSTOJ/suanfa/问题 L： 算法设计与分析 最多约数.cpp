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
    int a, b;
    while(cin >> a >> b)
    {
        int max = 0;
        int max_num = 0;
        for(int i = a; i <= b; i++)
        {
            int count = 0;
            for(int j = 1; j <= i; j++)
            {
                if(i % j == 0)
                    count++;
            }
            if(count > max)
            {
                max = count;
                max_num = i;
            }
        }
        cout << max << ' ' << max_num << endl;
    }
    return 0;
}
