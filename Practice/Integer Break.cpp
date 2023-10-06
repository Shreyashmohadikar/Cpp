class Solution {
private:
    int f(int n, vector<int> &dp){
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int maxprod = 1;
        for(int i=1; i<n; i++){
            int temp = max(i * (n-i), i * f(n-i, dp));
            maxprod = max(maxprod, temp);
        }
        return dp[n] = maxprod;
    }
public:
    int integerBreak(int n) {
       if(n<4){
           return n-1;
       }
       vector<int> dp(n+1, -1);
       return f(n, dp);
    }
};