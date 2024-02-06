#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int numdev(int n)
{
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            count++;
    }
    return count;
}   

int sumdiv(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            sum += i;
    }
    return sum;
}

int numSum(int a, int b)
{
    return a + b;
}

int main()
{
    int a,b;
    printf("Hello World 你好\n");
    cout << "请输入两个整数：" << endl;
    cin >> a >> b;
    cout << "两个整数的和为：" << numSum(a, b) << endl;
    //cout << "Hello World 你好" << endl;
    system("pause");
    return 0;
}