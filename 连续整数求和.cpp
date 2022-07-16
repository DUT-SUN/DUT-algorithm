//给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。
//输入: n = 5
//输出 : 2
//解释 : 5 = 2 + 3，共有两组连续整数([5], [2, 3])求和后为 5。
//O(根号n)
//由等差数列的得2n=(i+(i+k))*(k+1),i是最开始的数，k+1为项数
//令a等于右面项左面,b=右面
//推导得出2i=a-k

class Solution {
    bool check(int a, int b) {
        int i2 = a - (b - 1);
        if (i2 % 2) {
            return false;
        }
        if (i2 <= 0)
        {
            return false;
        }
        return true;
    }
public:
    int consecutiveNumbersSum(int n) {
        n *= 2;
        int ans = 0;
        //i为2n因子,n/i肯定是2n的因子所以只需要枚举到根号n
        int sn = sqrt(n);
        //枚举2n的因子
        for (int i = 1; i <= sn; ++i) {
            if (n % i == 0) {
                if (check(i, n / i)) {
                    ++ans;
                }
                if (i != n / i) {
                    if (check(n / i, i)) {
                        ++ans;
                    }
                }

            }
        }
        return ans;
    }
};