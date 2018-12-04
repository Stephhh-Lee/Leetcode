class Solution {
public:
    string int2str(const int &int_temp)
    {
        string string_temp;
        stringstream stream;
        stream<<int_temp;
        string_temp=stream.str();   //此处也可以用 stream>>string_temp
        return string_temp;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for(auto x:cpdomains){
            string s = "";
            int begin = 0, counter = 0;
            for(;x[begin] != ' '; begin++){
                counter = counter*10 + x[begin] - '0';
            }
            for(int i = x.size()-1; i >= begin; i--){
                if(x[i] == '.' || x[i] == ' ') m[s] += counter;
                s = x[i] + s;
            }
        }
        vector<string> ans;
        for(auto x:m){
            ans.push_back(int2str(x.second) + ' ' + x.first);
        }
        return ans;
    }
};
