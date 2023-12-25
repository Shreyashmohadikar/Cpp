class Solution {
private:
    int solve(string str, int i, vector<int> &dp){
        if(i < 0){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 0;
        //one char
        if(str[i] != '0'){
            ans += solve(str, i-1, dp);
        }
        //two chars
        if(i > 0 && (str[i-1] == '1' || str[i-1] == '2' && str[i] <= '6')){
            ans += solve(str, i-2, dp);
        }
        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(s, n-1, dp);
    }
};

/////////////////

class Solution {
private:
    int solve(string str, int i, vector<int> &dp){
        if(i == str.size()){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 0;
        //one char
        if(str[i] != '0'){
            ans += solve(str, i+1, dp);
        }
        //two chars
        if(i+1 < str.size() && (str[i] == '1' || str[i] == '2' && str[i+1] <= '6')){
            ans += solve(str, i+2, dp);
        }
        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(s, 0, dp);
    }
};
