//ɵ�����⣬�ĳ�long i�͹���
//ʹ�ö��ֿ��Լӿ��ٶȰ�

class Solution {
public:
    int mySqrt(int x) { 
        long i = 1;
        for(; i*i <= x; i++){
        }
        return i-1;
    }
};


/*
��һ�ֽⷨ�� ţ�ٵ�������˼��ο��ٶȰٿ� �Լ��ο����� 
Ϊ�˷�����⣬�����Ա���Ϊ���� 

����x2 = n�Ľ⣬��f(x)=x2-n���൱�����f(x)=0�Ľ⣬����ͼ��ʾ��

����ȡx0�����x0���ǽ⣬��һ������(x0,f(x0))���������ߣ���x��Ľ���Ϊx1��

ͬ���ĵ������x1���ǽ⣬��һ������(x1,f(x1))���������ߣ���x��Ľ���Ϊx2��

�Դ����ơ�

�������ķ�ʽ�õ���xi������������f(x)=0�Ľ⡣

�ж�xi�Ƿ���f(x)=0�Ľ������ַ�����

һ��ֱ�Ӽ���f(xi)��ֵ�ж��Ƿ�Ϊ0�������ж�ǰ��������xi��xi-1�Ƿ����޽ӽ���

����(xi, f(xi))���������߷���Ϊf(x) = f(xi) + f��(xi)(x - xi)������f��(x)Ϊf(x)�ĵ�����������Ϊ2x�������߷��̵���0���������xi+1=xi - f(xi) / f��(xi)��

��������xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2��
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            return -1;

        //ʹ�ö��ַ����
        unsigned long long lhs = 0, rhs = (x + 1) / 2;

        while (lhs <= rhs)
        {
            unsigned long long mid = (lhs + rhs) / 2;
            //ע��������⣬ʹ���޷��ų����ʹ洢��ʱ�˻�
            unsigned long long tmp1 = mid * mid;
            if (tmp1 == x)
            {
                return mid;
            }
            else if (tmp1 < x)
            {
                lhs = mid + 1;
            }               
            else{
                rhs = mid - 1;
            }//else
        }//while

        unsigned long long tmp = lhs * lhs;
        if (tmp <= x)
            return lhs;
        else
            return rhs;
    }
};
