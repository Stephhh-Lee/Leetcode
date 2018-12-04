class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), counter = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != val) counter++;
        }
        for(int i = len-1, j = counter-1; j >= 0; j--){
            while(nums[i] == val) i--;
            swap(nums[i], nums[j]);
        }
        return counter;
    }
};
