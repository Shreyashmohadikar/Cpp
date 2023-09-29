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

///////////////////////////////////////////////
//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, 
                                    vector<vector<int>> 
                                    (2,vector<int> (3, 0))); //3D DP

        // if (n == 0) return 0;
        //Base Case
        // for(int i=n-1; i>=0; i--){
        //     for(int buy=0; buy<=1; buy++){
        //         dp[i][buy][0] = 0;
        //     }
        // }
        // for(int i=n-1; i>=0; i--){
        //     for(int buy=0; buy<=1; buy++){
        //         dp[i][buy][0] = 0;
        //     }
        // }
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    int profit = INT_MIN;
                    if(buy == 0){
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][1][cap],
                                    0 + dp[i+1][0][cap]);
                    }
                    else{
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][0][cap-1],
                                    0 + dp[i+1][1][cap]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};