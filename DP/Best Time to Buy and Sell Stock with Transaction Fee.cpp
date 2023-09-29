class Solution {
public:
    int f(int i, int buy, vector<int> &prices, vector<vector<int>> &dp, int fee){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = INT_MIN;
        if(buy){
            profit = max(-prices[i] + f(i+1, 0, prices, dp, fee),
                        0 + f(i+1, 1, prices, dp, fee));
        }
        else{
            profit = max(prices[i] + f(i+1, 1, prices, dp, fee) - fee,
                        0 + f(i+1, 0, prices, dp, fee));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, 1, prices, dp, fee);
    }
};