class Solution {
private:
    unordered_map<int, vector<int>> map;
    int seed = 2333;
public:
    Solution(vector<int> nums) {
        for(int i=0; i<nums.size(); i++){
            map[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        if(map[target].size()==0) return -1;
        else{
            srand(seed);
            seed++;
            int i = rand()%(map[target].size());
            return map[target][i];
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */


class Solution {
public:
    vector<int> n;
    random_device rd;
    mt19937 gen;
    Solution(vector<int> nums):n(nums),gen(rd()){
    }
    
    int pick(int target) {
        int chosen = -1;
        int seen = 0;
        for(int i = 0; i < n.size(); ++i){
            if(n[i] == target){
                if(seen == 0){
                    chosen = i;
                }else{
                    int res = uniform_int_distribution<>(0,seen)(gen);
                    if(res <= 0){
                        chosen = i;
                    }
                }
                seen++;
            }
        }
        
        return chosen;
    }
};
