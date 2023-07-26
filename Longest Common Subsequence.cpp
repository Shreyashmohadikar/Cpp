class Solution {
public:
    int f(int L1, int L2, string &str1, string &str2, vector<vector<int>> &dp){
        if(L1 < 0 || L2 < 0){
            return 0;
        }
        if(dp[L1][L2] != -1){
            return dp[L1][L2];
        }
        if(str1[L1] == str2[L2]){
            return 1 + f(L1-1, L2-1, str1, str2, dp);
        }
        return dp[L1][L2] = max(f(L1-1, L2, str1, str2, dp), f(L1, L2-1, str1, str2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int L1 = text1.size();
        int L2 = text2.size();
        vector<vector<int>> dp(L1+1, vector<int>(L2+1, -1));
        return f(L1-1, L2-1, text1, text2, dp);
    }
};

//match & notMatch