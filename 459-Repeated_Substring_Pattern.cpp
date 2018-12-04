class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool tmp = false;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[0]){
                if(helper(s, i)) return true;
            }
        }
        return false;
    }
    bool helper(string s, int len){
        if(s.size() % len != 0) return false;
        for(int i = len; i < s.size(); i++){
            if(s[i] != s[i%len]) return false;
        }
        return true;
    }
};

//�����ǰ���ķ�����������һ����Ż�������ac���ǲ����ð�
//���渴ϰһ��KMP
/*
KMP����Ҫ˼���������ַ��������ǰ׺��׺�ĶԳ��ԣ�������next���飬�Ӷ�ʵ��
�ýӽ�O(N)��ʱ�临�Ӷ�����ַ�����ƥ��

����һ���ַ���str��next[j] = k ��ʾ����str[0...k-1] = str[j-k...j-1]�����
��k���������Ӵ�str[0...j-1]��ǰk����ĸ���ں�k����ĸ


���str��next���飻
��ʼ����next[0] = -1
1�����str[j]==str[k]����next[j+1] = k+1
2�����str[j]!=str[k]����k=next[k]��Ȼ�����ѭ�����ص�1����ֱ��k=-1

*/

bool repeatedSubstringPattern(string str)
{
    int len = str.length();
    int next[len+1];
    next[0] = -1;
    int j = 0, k = -1;
    while( j<len )
    {
        if( k==-1 || str[j]==str[k] )
            next[++j] = ++k;
        else k = next[k];
    }
    int i=0;
    return next[len]&&next[len]%(len-next[len])==0;
}
