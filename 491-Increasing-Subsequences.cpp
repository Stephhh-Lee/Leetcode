class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res; // use set to filter same solution
        vector<int> tmp; // a solution item
        dfs(nums, res, tmp, 0);
        return vector<vector<int>> (res.begin(), res.end());
    }


    void dfs(vector<int>& nums, set<vector<int>>& res, vector<int> tmp, int k) {

        /*
            k: start index for DFS
         */

        if (tmp.size() >= 2) res.insert(tmp);

        for (int i = k; i < nums.size(); ++i) {
            // append element into tmp when it is empty
            // or the new element is not less then the last element
            if (tmp.size() == 0 || nums[i] >= tmp.back()) {
                tmp.push_back(nums[i]);
                dfs(nums, res, tmp, i+1); //iteratively dfs among the remaining elements
                tmp.pop_back();
            }
        }
    }
};
