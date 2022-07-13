#define _CRT_SECURE_NO_WARNINGS 1
//目的：寻找子串出现的个数


#include<iostream>
#include<cstring>
using namespace std;
#define ULL unsigned long long
#define K 103
int N;
char s1[1000005], s2[1000005];
ULL f[1000005], l1, l2, t;
ULL a[1000005];
ULL get(int x, int y)
{
    return f[y] - f[x - 1] * a[y - x + 1];
}
int main()
{
    a[0] = 1;
    for (int i = 1; i <= 1000000; ++i)//预处理出a^n
        a[i] = a[i - 1] * K;
 
        int ans(0); t = 0;  
        strcpy(s2+1, "hznu");
        cin >> s1 + 1;
        
        l1 = strlen(s1 + 1); l2 = strlen(s2 + 1);
        for (int j = 1; j <= l1; ++j)
            f[j] = f[j - 1] * K + (s1[j] - 'A');
        for (int j = 1; j <= l2; ++j)
            t = t * K + (s2[j] - 'A');
        for (int j = 1; j + l2 - 1 <= l1; ++j)
        {
            if (get(j, j + l2 - 1) == t) 
                ans++;
        }
        cout << ans;
    
    return 0;
}