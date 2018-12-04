class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;
        for(auto x:bills){
            if(x==5) m[5]++;
            if(x==10){
                if(!m[5]) return false;
                m[10]++;
                m[5]--;
            }
            if(x==20){
                m[20]++;
                if(!m[5]) return false;
                else if(m[10] && m[5]){
                    m[10]--;
                    m[5]--;
                }
                else{
                    if(m[5]<3) return false;
                    m[5]-=3;
                }
            }
        }
        return true;
    }
};
