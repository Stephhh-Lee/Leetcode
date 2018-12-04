//��������ɸ��
/*
����������Ƚ� 2~n �ĸ�����������У�Ȼ����2�����滭һ��ԲȦ��Ȼ��ȥ2��
������������һ����δ��Ȧ��û�б���ȥ������3��������Ȧ���ٻ�ȥ3������������
���ڼ�δ��Ȧ��û�б���ȥ�ĵ�һ���� ��5��������Ȧ������ȥ5������������������
���ƣ�һֱ������С�ڻ���� n �ĸ���������Ȧ��ȥΪֹ����ʱ�����л���Ȧ��
�Լ�δ��ȥ����Щ�����þ���С�� n ��������
*/


class Solution {
public:
    int countPrimes(int n) {
        bool* del = new bool[n];
        del[2] = false;
        for(int i = 3; i < n; i++) {
            if(i%2==0) del[i] = true;
            else del[i] = false;
        }
        for(int i = 3; i < n; i+=2){
            if(!del[i]){
                if(i*i > n) break;
                for(int j = 2; j*i < n; j++){
                    del[i*j] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(!del[i]) ans++;
        }
        return ans;
    }
};
