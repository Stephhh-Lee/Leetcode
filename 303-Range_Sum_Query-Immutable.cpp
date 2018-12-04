class NumArray {
private:
    vector<int> n;
public:
    NumArray(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++){
            n.push_back(nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        int ans = 0;
        for(;i<=j;i++)
            ans+=n[i];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */