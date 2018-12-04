class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int totalDresses = 0, size = machines.size();
        for (auto i = 0; i < size; ++i) totalDresses += machines[i];
        if (totalDresses % size != 0) return -1;

        auto targetDresses = totalDresses / size, totalMoves = 0, ballance = 0;
        for (auto i = 0; i < size; ++i) {
            ballance += machines[i] - targetDresses; //这里是通过第i个点的衣服的数量，也就是（0~i）与（i+1，n）衣服的差
            totalMoves = max(totalMoves, max(machines[i] - targetDresses, abs(ballance)));
        }
        return totalMoves;
    }
};
