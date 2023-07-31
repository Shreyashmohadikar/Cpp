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
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), 
                                        vector<vector<int>> (2, 
                                            vector<int> (3, -1))); //3D DP
        return f(0, 1, 2, prices, dp);
    }
};