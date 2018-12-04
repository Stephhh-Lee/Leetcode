class Solution {
public:
    int str_to_int(string s){
        stringstream ss;
        ss<<s;
        int a;
        ss>>a;
        return a;
    }
    string int_to_string(vector<int>& v){
        string s1 = "", s2 = "";
        stringstream ss1, ss2;
        ss1<<v[0];
        ss2<<v[1];
        ss1>>s1;
        ss2>>s2;
        return s1+'+'+s2+'i';
    }
    string complexNumberMultiply(string a, string b) {
        vector<int> va;
        vector<int> vb;
        string s = "";
        for(int i = 0; i < a.size(); i++){
            if(a[i] != '+' && a[i] != 'i') s+=a[i];
            else {
                va.push_back(str_to_int(s));
                s = "";
            }
        }
        s = "";
        for(int i = 0; i < b.size(); i++){
            if(b[i] != '+' && b[i] != 'i') s+=b[i];
            else {
                vb.push_back(str_to_int(s));
                s = "";
            }
        }
        vector<int> ans(2);
        ans[0] = va[0]*vb[0] - va[1]*vb[1];
        ans[1] = va[0]*vb[1] + va[1]*vb[0];
        return int_to_string(ans);
    }
};
