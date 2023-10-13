class Solution
{
private:
    int f(int i, vector<int> &cost, vector<int> &dp)
    {
        if (i < 0)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int take1 = f(i - 1, cost, dp);
        int take2 = f(i - 2, cost, dp);
        return dp[i] = cost[i] + min(take1, take2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(f(n - 1, cost, dp), f(n - 2, cost, dp));
    }
};