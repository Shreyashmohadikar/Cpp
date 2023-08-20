class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i=1; i*i <= n; i++){
            ans = min(ans, 1 + f(n - i*i, dp));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};

////////////////////////Tabulation

class Solution {
public:
    int numSquares(int n) {
        if(n<=3){
            return n;
        }
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            for(int x=1; x*x<=i; x++){
                dp[i] = min(dp[i], 1 + dp[i-x*x]);
            }
        }
        return dp[n];
    }
};