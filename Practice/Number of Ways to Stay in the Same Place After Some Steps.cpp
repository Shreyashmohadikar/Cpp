class Solution {
private:
    const int MOD = 1e9 + 7;
    int f(int pos, int steps, int arrLen, vector<vector<int>>& dp) {
        if (steps == 0) {
            if (pos == 0) return 1;
            else return 0;
        }
        if (pos < 0 || pos >= arrLen) {
            return 0;
        }
        if (dp[pos][steps] != -1) {
            return dp[pos][steps];
        }

        long long stay = f(pos, steps - 1, arrLen, dp);
        long long right = f(pos + 1, steps - 1, arrLen, dp);
        long long left = f(pos - 1, steps - 1, arrLen, dp);

        return dp[pos][steps] = (stay + left + right) % MOD;
    }
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return f(0, steps, arrLen, dp);
    }
};
