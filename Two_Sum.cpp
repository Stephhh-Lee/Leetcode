#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> toSum(vector<int>& nums, int target){
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
        if(m.find(target - nums[i]) == m.end()){
            m[nums[i]] = i;
        }
        else{
            vector<int> v;
            v.push_back(m[target - nums[i]);
            v.push_back(i);
            return v;
        }
    }
}
int main(){
    vector<int> i =[3,2,4];
    int tar = 6;
    vector<int> ans;
    ans = twoSum(i, tar);
    cout<<ans;
}
