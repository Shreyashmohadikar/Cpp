class Solution {
public:
    int f(int n, int amount, vector<int> &arr, vector<vector<int>> &dp){
        if(n == 0){
            if(amount % arr[n] == 0){
                return amount / arr[n];
            }
            else {
                return 1e9;
            }
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        int notTake = 0 + f(n-1, amount, arr, dp);
        int take = INT_MAX;
        if(amount >= arr[n]){
            take = 1 + f(n, amount-arr[n], arr, dp);
        }
        return dp[n][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};