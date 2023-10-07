class Solution
{
public:
    const int MOD = 1e9 + 7;

    long long f(int curr_idx, int n, int m, int k, int curr_k,
                int maxSoFar, vector<vector<vector<long long>>> &dp)
    {
        // Base case
        if (curr_idx == n)
        {
            if (curr_k == k)
            {
                return 1;
            }
            return 0;
        }

        if (dp[curr_idx][maxSoFar + 1][curr_k] != -1)
        {
            return dp[curr_idx][maxSoFar + 1][curr_k];
        }

        long long ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int newMaxSoFar = maxSoFar;
            int newCurr_k = curr_k;

            if (i > maxSoFar)
            {
                newMaxSoFar = i;
                newCurr_k++;
            } // Algo as mentioned in question

            ans = (ans + f(curr_idx + 1, n, m, k, newCurr_k, newMaxSoFar, dp)) % MOD;
        }
        return dp[curr_idx][maxSoFar + 1][curr_k] = ans;
    }

    int numOfArrays(int n, int m, int k)
    {
        vector<vector<vector<long long>>> dp(n + 1,
                                             vector<vector<long long>>(m + 2,
                                                                       vector<long long>(n + 1, -1)));
        return f(0, n, m, k, 0, -1, dp);
    }
};
