//这道题有点好玩了啊，面对两种方案的选择，使用了回滚的思路。
//就像时间刺客的大招一样。

class Solution {
public:
    bool validPalindrome(string s) {
        int chance = 0;
        int ki,kj;
        for(int i=0,j=s.size()-1; i<j;){
            if(s[i]==s[j]){i++;j--;}
            //else if(s[i]==s[j-1]) j--;
            //else if(s[i+1]==s[j]) i++;
            else{
                if(chance == 0){
                    ki=i;
                    kj=j;
                    i++;
                    chance++;
                }
                else if(chance == 1){
                    i=ki;
                    j=kj;
                    j--;
                    chance++;
                }
                else return false;
            }
            //else return false;
        }
        return true;
    }
};
