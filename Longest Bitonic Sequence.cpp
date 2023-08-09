int longestBitonicSubsequence(vector<int> &arr, int n)
{
    vector<int> dp(n, 1);
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], dp[prev] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[prev] < arr[i] && dp1[prev] + 1 > dp1[i])
            {
                dp1[i] = max(dp1[i], dp1[prev] + 1);
            }
        }
    }
    int lbs = 1;
    for (int i = 0; i < n; i++)
    {
        lbs = max(lbs, dp[i] + dp1[i] - 1);
    }
    return lbs;
}
