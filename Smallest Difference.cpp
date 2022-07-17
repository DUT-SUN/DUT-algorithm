#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    int a[10010];
    cin >> t;
    int N = 0;//记录输入的最大的数值
    while (t--)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));//清空数组a
        for (int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            a[b]++;//记录数组元素中值为b的个数
            if (b > N)
                N = b;//记录数组元素中最大的数值
        }
        int maxx = 0;//记录最大的相邻元素的总数
        for (int i = 0; i <= N; i++)
        {
            if (a[i] != 0)// 0 1 1 1=>0 2 1 1 maxx=2=>0 2 2 1 maxx=2=>0 2 2 1 maxx=2
                a[i] += a[i + 1];//并不使用a[i-1]是因为最小的数没有
            maxx = max(maxx, a[i]);
        }
        cout << maxx << endl;
    }
}
