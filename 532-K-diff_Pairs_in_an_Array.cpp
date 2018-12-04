class Solution {
public:

    int findPairs(vector<int>& nums, int k) {
        if(k < 0 || nums.size() <= 1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int count = 0;
        int left = 0;
        int right = 1;

        while(right < nums.size()){
            int firNum = nums[left];
            int secNum = nums[right];
            if(secNum - firNum < k)
                right++;
            else if(secNum - firNum > k)
                left++;
            else{
                count++;
                while(left < nums.size() && nums[left] == firNum)
                    left++;
                while(right < nums.size() && nums[right] == secNum)
                    right++;
            }
            if(right == left)
                right++;
        }
        return count;
    }
    /*
    int findPairs(vector<int>& nums, int k) {
        if(k<0 || nums.size()<=1){
            return 0;
        }

        sort(nums.begin(), nums.end());
        int count = 0;
        int left = 0;
        int right = 1;

        while(right<nums.size()){
            int firNum = nums[left];
            int secNum = nums[right];
            if(secNum-firNum<k)
                right++;
            else if(secNum - firNum>k)
                left++;
            else{
                count++;
                while(left<nums.size() && nums[left]==firNum){
                    left++;
                }
                while(right<nums.size() && nums[right]==secNum){
                    right++;
                }

            }
            if(right==left){
                right++;
            }
        }
        return count;
    }
    */
};
