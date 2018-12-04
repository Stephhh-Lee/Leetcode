class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> hold(n, 0), unhold(n, 0);
        hold[0] = -prices[0];

        for (int i = 1; i < n; i++) {
            unhold[i] = max(unhold[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], unhold[i - 1] - prices[i]);
        }
        return unhold[n - 1];
    }
};
