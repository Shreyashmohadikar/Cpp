class Solution {
public:
    int f(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i == prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = INT_MIN;
        if(buy){
            profit = max(-prices[i] + f(i+1, 0, prices, dp),
                        0 + f(i+1, 1, prices, dp));
        }
        else{
            profit = max(prices[i] + f(i+1, 1, prices, dp),
                        0 + f(i+1, 0, prices, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};

////////////////////////////////////////////////////////
//using bool

class Solution {
public:
    int f(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i == prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = INT_MIN;
        if(buy){
            profit = max(-prices[i] + f(i+1, false, prices, dp),
                        0 + f(i+1, true, prices, dp));
        }
        else{
            profit = max(prices[i] + f(i+1, true, prices, dp),
                        0 + f(i+1, false, prices, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, true, prices, dp);
    }
};

//////////////////////
//Tabulation


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0; // base case

        for (int i = n - 2; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = INT_MIN;
                if (buy) {
                    profit = max(-prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                } else {
                    profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
                dp[i][buy] = profit; // update the dp table
            }
        }
        return dp[0][1]; // return the maximum profit achieved by selling on the first day
    }
};
