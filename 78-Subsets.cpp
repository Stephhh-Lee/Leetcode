class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int> vec, vector<int>& nums, int index){
        if(index >= nums.size()){
            ans.push_back(vec);
            return;
        }
        /*
        for(int i=index; i<index+1; i++){
            vec.push_back(nums[i]);
            helper(ans, vec, nums, i+1);
            vec.pop_back();
            helper(ans, vec, nums, i+1);
        }*/
        vec.push_back(nums[index]);
        helper(ans, vec, nums, index+1);
        vec.pop_back();
        helper(ans, vec, nums, index+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        helper(ans, vec, nums, 0);
        return ans;
    }
};
