class Solution {
public:
    int f(int n, int m, string &s, string &t, vector<vector<int>> &dp){
        if(m<0){
            return n+1;
        }
        if(n<0){
            return m+1;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(s[n] == t[m]){
            return dp[n][m] = f(n-1, m-1, s, t, dp);
        }
        return dp[n][m] = 1 + min({f(n-1, m, s, t, dp), f(n, m-1, s, t, dp), f(n-1, m-1, s, t, dp)});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
};