class Solution {
public:
    int f(int L1, int L2, string &s, string &t, vector<vector<int>> &dp){
        if(L1<0 || L2<0){
            return 0;
        }
        if(dp[L1][L2] != -1){
            return dp[L1][L2];
        }
        if(s[L1] == t[L2]){
            return dp[L1][L2] = 1 + f(L1-1, L2-1, s, t, dp);
        }
        return dp[L1][L2] = max(f(L1, L2-1, s, t, dp), f(L1-1, L2, s, t, dp));
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int l1 = s.size();
        vector<vector<int>> dp(l1, vector<int>(l1, -1));
        return (l1 - f(l1-1, l1-1, s, t, dp));
    }
};
