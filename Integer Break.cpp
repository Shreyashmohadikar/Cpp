class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int maxpro = n;
        for(int i=1; i<=n/2; i++){
            maxpro = max(maxpro, i * f(n-i, dp));
        }
        return dp[n] = maxpro;
    }
    int integerBreak(int n) {
        if(n<4){
            return n-1;
        }
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};


////////////////////////

class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int maxpro = 1;
        for(int i=1; i<n; i++){
            int temp = max(i * (n-i), i * f(n-i, dp));
            maxpro = max(maxpro, temp);
        }
        return dp[n] = maxpro;
    }
    int integerBreak(int n) {
        if(n<4){
            return n-1;
        }
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};