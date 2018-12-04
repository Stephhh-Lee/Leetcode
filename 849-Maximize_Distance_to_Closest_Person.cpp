class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, n = seats.size();
        for(int i = 0, zero = 0; i < n; ++i)
            if(seats[i] == 1) zero = 0;
            else res = max(res, (++zero + 1)/2);
        for(int i = 0, zero = 0; seats[i] == 0; ++i)
            res = max(res, ++zero);
        for(int i = n - 1, zero = 0; seats[i] == 0; --i)
            res = max(res, ++zero);
        return res;
    }
};
