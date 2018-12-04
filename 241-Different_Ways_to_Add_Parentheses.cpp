//有错误，就是。。他们会把乘法一次算完，我是一次选出来一个运算进行计算


class Solution {
public:
    
    struct Result{
        vector<int> numR;;
        vector<char> opeR;
    };
    
    struct Result calculate(vector<char> ope, vector<int> num, int i){
        switch(ope[i]){
            case '+':num[i]+=num[i+1]; break;
            case '-':num[i]-=num[i+1]; break;
            case '*':num[i]*=num[i+1]; break;
            default:break;
        }
        ope.erase(ope.begin()+i);
        num.erase(num.begin()+i+1);
        struct Result ret;
        ret.numR=num;
        ret.opeR=ope;
        return ret;
    }
    void helper(vector<char> ope, vector<int> num, vector<int>& ans){
        if(num.size()==1){
            ans.push_back(num[0]);
            return;
        }
        else{
            for(int i=0; i<ope.size(); i++){
                if(ope[i]!='*' || (ope[i]=='*')){
                    struct Result r = calculate(ope, num, i);
                    helper(r.opeR, r.numR, ans);
                }
            }
        }
    }
    
        
    int to_int(string s){
        stringstream ss;
        ss<<s;
        int ret;
        ss>>ret;
        return ret;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        vector<char> ope;
        vector<int> num;
        string s="";
        for(auto x:input){
            if(x=='+' || x=='-' || x=='*'){
                num.push_back(to_int(s));
                ope.push_back(x);
                s.clear();
            }
            else {
                s+=x;
            }
        }
        num.push_back(to_int(s));
        
        helper(ope, num, ans);
        return ans;
    }
};
