#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int main()
{
    long n,m;
    while(cin>>m>>n)
    {
        long a=m,b=n;
        while(m%n != 0)
        {
			long tmp = m%n;
			m = n;
			n = tmp;
		}
		cout << n << ' ' << a*b/n << endl;
    }
    return 0;
}
