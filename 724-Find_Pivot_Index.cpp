class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        for(int i=0,j=nums.size()-1; i<nums.size(); i++,j--){
            if(i==0) left[i] = nums[i];
            else left[i] = nums[i] + left[i-1];
            if(j==nums.size()-1) right[j] = nums[j];
            else right[j] = nums[j] + right[j+1];
        }
        for(int i = 0; i < nums.size(); i++){
            if(right[i] == left[i] ) return i;
        }
        return -1;
    }
};
