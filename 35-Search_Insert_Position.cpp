//这他妈是标准的二分查找？？

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-2, mid;
        while(s <= e){
            mid = s+(e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e = mid - 1;
            else s = mid + 1;
        }
        if(target > nums[s]) return s+1;
        else return s;
        //return e;
    }
};


//改了while的判断条件

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1, mid;
        while(s < e){
            mid = (s+e)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e = mid - 1;
            else s = mid + 1;
        }
        //if(target == nums[s]) return s;
        if(target > nums[s]) return s+1;
        else return s;
        //return e;
    }
};
