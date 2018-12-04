class Solution {
public:
    unordered_map<string, int> m;
    string int2str(int num){
        stringstream ss;
        ss<<num;
        string s;
        ss>>s;
        return s;
    }
    bool isLegal(vector<int> v, string& s){
        int hour = 0, minute = 0;
        for(int i = 0; i < 4; i++){
            hour = hour*2 + v[i];
        }
        for(int i = 4; i < 10; i++){
            minute = minute*2 + v[i];
        }
        if(minute>=10)
            s = int2str(hour)+":"+int2str(minute);
        else if(minute == 0) s = int2str(hour)+":00";
        else s = int2str(hour)+":0"+int2str(minute);
        if(hour < 12 && minute < 60) return true;
        else return false;
    }
    //string toTime(vector<int> v){
    //}
    void helper(vector<string>& ans, vector<int> v, int num, int i){
        if(num == 0){
            string s;
            bool tmp = isLegal(v, s);
            if(tmp && m[s]==0) {ans.push_back(s); m[s]++;}
            //if(tmp) {ans.push_back(s);}
        }
        if(i<v.size()){
            helper(ans, v, num, i+1);
            v[i] = 1;
            helper(ans, v, num-1, i+1);
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        vector<int> v(10, 0);
        helper(ans, v, num, 0);

        return ans;
    }
};
