class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int diff = 0;
        for(int i = 0; i < arr.size(); i++){
            if(diff == 0) ans++;
            diff += arr[i] - i;
        }
        return ans;
    }
};
