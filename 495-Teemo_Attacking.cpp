class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        if(timeSeries.size()!=0){
            int start;// = timeSeries[0];
            int end;// = start + duration;
            for(int i = 0; i < timeSeries.size(); i++){
                start = timeSeries[i];
                end = start + duration;
                while(timeSeries[i+1]<=end && i < timeSeries.size()-1){
                    end = timeSeries[i+1] + duration;
                    i++;
                }
                ans += end - start;
                //if(i==timeSeries.size()-1) ans += duration;
            }
        }
        //if(timeSeries.size()==1) return duration;
        //ans += end - start;
        return ans;
    }
};
