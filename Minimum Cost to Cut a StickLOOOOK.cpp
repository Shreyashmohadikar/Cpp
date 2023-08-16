class Solution
{
public:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;

        for (int k = i; k <= j; k++)
        {
            int cost = arr[j + 1] - arr[i - 1] + f(i, k - 1, arr, dp) + f(k + 1, j, arr, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));

        return f(1, c, cuts, dp);
    }
};