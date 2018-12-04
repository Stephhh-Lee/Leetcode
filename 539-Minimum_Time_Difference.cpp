/*
class Solution {
public:
    int str2int(const string &string_temp)
    {
        int int_temp;
        int_temp=atoi(string_temp.c_str());
        return int_temp;
    }
    int findDifference(pair<int, int> a, pair<int, int> b){
        int ans;
        ans = abs((a.first-b.first+24)%24*60+(a.second-b.second));
        return min(ans, 60*24-ans);
    }
    bool cmp2(const pair<int, int>a, const pair<int, int>b)
    {
        return a.second < b.second;
    }
    int findMinDifference(vector<string>& timePoints){
        vector<pair<int, int>> p;
        int ans;
        //p.resize(timePoints.size());
        for(int i = 0; i < timePoints.size(); i++){
            //p[i].first = str2int(timePoints[i].substr(0, 2));
            //p[i].second = str2int(timePoints[i].substr(3, 5));
            p.push_back(make_pair(str2int(timePoints[i].substr(0, 2)), str2int(timePoints[i].substr(3, 5))));
        }
        sort(p.begin(), p.end(), cmp2);
        for(int i = 0; i < p.size(); i++){
            ans = min(ans, findDifference(p[i], p[i+1]));
        }
        return ans;
    }
};
*/

class Solution {
public:
    int time2int(string str){
        return ((str[0]-'0')*600 + (str[1]-'0')*60 + (str[3]-'0')*10 + (str[4]-'0'));

    }
    int findMinDifference(vector<string>& timePoints){
        int ans = 1440;
        int prev = -1440, first = -1;
        vector<bool> tmp(1440, false);
        for(auto x:timePoints){
            if(tmp[time2int(x)] == true)
                return 0;
            else tmp[time2int(x)] = true;
        }
        for(int i = 0; i < 1440; i++){
            if(tmp[i] == true){
                if(first == -1) first = i;
                ans = min(ans, i - prev);
                prev = i;
            }
        }
        ans = min(ans, 1440 - prev + first);
        return ans;
    }
};
