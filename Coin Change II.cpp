class Solution {
public:
    int f(int n, int amount, vector<int> &arr, vector<vector<int>> &dp){
        if(n == 0){
            return (amount % arr[n] == 0);
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        int notTake = f(n-1, amount, arr, dp);
        int take = 0;
        if(amount >= arr[n]){
            take = f(n, amount-arr[n], arr, dp);
        }
        return dp[n][amount] = (take + notTake);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        return ans;
    }
};
