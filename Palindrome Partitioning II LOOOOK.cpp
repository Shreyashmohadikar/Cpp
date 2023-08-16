class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(int i, string &s, int n, vector<int> &dp){
        if(i == n){
            return -1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mini = n-i-1;
        for(int j=i; j<n; j++){
            if(isPalindrome(s, i, j)){
                int cost = 1 + f(j+1, s, n, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, n, dp);
    }
};