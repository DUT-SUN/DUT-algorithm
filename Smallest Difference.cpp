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
    int N = 0;//��¼�����������ֵ
    while (t--)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));//�������a
        for (int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            a[b]++;//��¼����Ԫ����ֵΪb�ĸ���
            if (b > N)
                N = b;//��¼����Ԫ����������ֵ
        }
        int maxx = 0;//��¼��������Ԫ�ص�����
        for (int i = 0; i <= N; i++)
        {
            if (a[i] != 0)// 0 1 1 1=>0 2 1 1 maxx=2=>0 2 2 1 maxx=2=>0 2 2 1 maxx=2
                a[i] += a[i + 1];//����ʹ��a[i-1]����Ϊ��С����û��
            maxx = max(maxx, a[i]);
        }
        cout << maxx << endl;
    }
}
