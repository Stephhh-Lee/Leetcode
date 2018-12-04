class Solution {
    vector<int> ori, data;
public:
    Solution(vector<int> nums):ori(nums), data(nums) {

    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=data.size()-1; i>=0; --i)
            swap(data[i], data[rand()%(i+1)]);
        return data;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
