/*
找loop的题目：
使用快慢指针***
*/
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0)
                continue;
            int slow = i;
            int fast = getIndex(slow, nums);
            while (nums[i] * nums[fast] > 0 && nums[i] * nums[getIndex(fast, nums)] > 0){
                if (slow == fast){
                    if (slow == getIndex(slow, nums))
                        break;
                    return true;
                }
                slow = getIndex(slow, nums);
                fast = getIndex(getIndex(fast, nums), nums);
            }
            slow = i;
            int val = nums[slow];
            while(nums[slow] * val > 0){
                int next = getIndex(slow, nums);
                nums[slow] = 0;
                slow = next;
            }
        }
        return false;
    }

    int getIndex(int i, vector<int>& nums){
        int n = nums.size();
        return i + nums[i] >= 0? (i + nums[i]) % n : n + ((i + nums[i]) % n);
    }
};
