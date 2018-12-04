class Solution {
public:
    void reverseVec(vector<int>& nums, int start, int end){
        //if(start<end){
        for(int i = start; i < (start+end)/2+1; i++){
            swap(nums[i], nums[end-i+start]);
        }
        //}
    }
    
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        k = nums.size()-k;
        reverseVec(nums, 0, k-1);
        reverseVec(nums, k, nums.size()-1);
        reverseVec(nums, 0, nums.size()-1);
    }
};