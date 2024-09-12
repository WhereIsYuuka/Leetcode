#include<iostream>
using namespace std;

int main()
{
    long n;
    while(cin >> n)
    {
        long res = 1;
        for(int i = 1; i <= n; i++)
        {
            res *= i;
        }
        cout << res << endl;
    }
}
