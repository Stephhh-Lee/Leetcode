class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0, tail = nums.size() - 1;
        int mid;
        for(mid=(head+tail)/2; head <= tail;){
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                tail = mid - 1;
                mid = (head+tail)/2;
            }else{
                head = mid + 1;
                mid = (head+tail)/2;
            }

        }
        return -1;
    }
};
