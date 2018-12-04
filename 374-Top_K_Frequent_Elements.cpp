class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<pair<int, int>> vm;
        for (auto it = m.begin(); it != m.end(); it++)
            vm.push_back(make_pair(it->first, it->second));

        sort(vm.begin(), vm.end(), [](const pair<int,int>& a, const pair<int, int>& b) -> int {
            return a.second>b.second;
        });
        //std::sort(m.begin(), m.end(),
        //  [=](std::pair<int, int>& a, std::pair<int, int>& b) { return a.second < b.second; });
        vector<int> ans;
        int counter = 0;
        for(auto it=vm.begin();it!=vm.end();it++){
            ans.push_back(it->first);
            if(++counter>=k) break;
        }
        return ans;
    }

};
