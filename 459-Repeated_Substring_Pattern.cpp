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

//上面是包里的方法，经过了一点点优化，过了ac但是不够好吧
//下面复习一下KMP
/*
KMP的主要思想是利用字符串自身的前缀后缀的对称性，来构建next数组，从而实现
用接近O(N)的时间复杂度完成字符串的匹配

对于一个字符串str，next[j] = k 表示满足str[0...k-1] = str[j-k...j-1]的最大
的k，即对于子串str[0...j-1]，前k个字母等于后k个字母


求解str的next数组；
初始化：next[0] = -1
1、如果str[j]==str[k]，则next[j+1] = k+1
2、如果str[j]!=str[k]，则k=next[k]，然后继续循环（回到1），直到k=-1

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
