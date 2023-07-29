class Solution {
public:
    bool f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0; k<=j; k++){
                if(t[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j] || t[j] == '?'){
            return dp[i][j] = f(i-1, j-1, s, t, dp);
        }
        if(t[j] == '*'){
            return dp[i][j] = (f(i-1, j, s, t, dp) 
                                || f(i, j-1, s, t, dp) 
                                || f(i-1, j-1, s, t, dp));  //taking all cases
        }
        return dp[i][j] = false; 
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, p, dp);
    }
};
