class Solution {
public:
    int f(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(cap == 0 || i == prices.size()){ // Base Case
            return 0;
        }
        if(dp[i][buy][cap] != -1){
            return dp[i][buy][cap];
        }
        int profit = INT_MIN;
        if(buy){
            profit = max(-prices[i] + f(i+1, 0, cap, prices, dp) ,
                        0 + f(i+1, 1, cap, prices, dp));
        }
        else{
            profit = max(prices[i] + f(i+1, 1, cap-1, prices, dp),
                        0 + f(i+1, 0, cap, prices, dp));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), 
                                        vector<vector<int>> (2, 
                                            vector<int> (k+1, -1))); //3D DP
        return f(0, 1, k, prices, dp);
    }
};

/////////////////////////////////////////
//Tabulation


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0; // base case

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[i][0] = max(-prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                } else {
                    dp[i][1] = max(prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
            }
        }
        return dp[0][0]; // return the maximum profit achieved by selling on the first day
    }
};