//�����set�����ԣ�

//����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����set��Ԫ�ز���map��������ͬʱӵ��ʵֵ
//(value)�ͼ�ֵ(key),setԪ�صļ�ֵ����ʵֵ��ʵֵ���Ǽ�ֵ��set����������Ԫ��
//����ͬ�ļ�ֵ��

//��С��������


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int num : nums){
            s.insert(num);
            if(s.size() > 3){
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};
