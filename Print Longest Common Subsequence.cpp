#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int f(int L1, int L2, string &str1, string &str2, vector<vector<int>> &dp){
        if(L1 < 0 || L2 < 0){
            return 0;
        }
        if(dp[L1][L2] != -1){
            return dp[L1][L2];
        }
        int match = 0;
        if(str1[L1] == str2[L2]){
            match = 1 + f(L1-1, L2-1, str1, str2, dp);
        }
        int notMatch = max(f(L1-1, L2, str1, str2, dp), f(L1, L2-1, str1, str2, dp));
        return dp[L1][L2] = max(match, notMatch);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int L1 = text1.size();
        int L2 = text2.size();
        vector<vector<int>> dp(L1+1, vector<int>(L2+1, -1));
        int lcsLength = f(L1-1, L2-1, text1, text2, dp);
        
        // Tracing back the LCS
        int i = L1 - 1;
        int j = L2 - 1;
        string lcs;
        while (i >= 0 && j >= 0) {
            if (text1[i] == text2[j]) {
                lcs = text1[i] + lcs;
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        
        cout << "Longest Common Subsequence: " << lcs << endl;
        return lcsLength;
    }
};

int main() {
    Solution sol;
    string text1 = "AGGTAB";
    string text2 = "GXTXAYB";
    int lcsLength = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of LCS: " << lcsLength << endl;
    return 0;
}
