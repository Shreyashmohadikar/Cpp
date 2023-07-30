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
