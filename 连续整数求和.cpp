//����һ�������� n������ ����������������������֮��Ϊ n ������ ��
//����: n = 5
//��� : 2
//���� : 5 = 2 + 3������������������([5], [2, 3])��ͺ�Ϊ 5��
//O(����n)
//�ɵȲ����еĵ�2n=(i+(i+k))*(k+1),i���ʼ������k+1Ϊ����
//��a��������������,b=����
//�Ƶ��ó�2i=a-k

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
        //iΪ2n����,n/i�϶���2n����������ֻ��Ҫö�ٵ�����n
        int sn = sqrt(n);
        //ö��2n������
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