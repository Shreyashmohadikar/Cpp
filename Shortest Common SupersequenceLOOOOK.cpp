class Solution {
public:
    int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp) {
        if (ind1 == 0 || ind2 == 0) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if (s1[ind1 - 1] == s2[ind2 - 1]) {
            return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
        } else {
            return dp[ind1][ind2] = max(f(ind1 - 1, ind2, s1, s2, dp), f(ind1, ind2 - 1, s1, s2, dp));
        }
    }

    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int lcsLength = f(n, m, s1, s2, dp);
        int scsLength = n + m - lcsLength;

        int i = n;
        int j = m;
        string ans = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
                lcsLength--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += s1[i - 1];
                i--;
            } else {
                ans += s2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += s1[i - 1];
            i--;
        }
        while (j > 0) {
            ans += s2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};