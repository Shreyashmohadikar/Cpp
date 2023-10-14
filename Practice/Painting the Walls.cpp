class Solution
{
private:
    int f(int i, int totalTime, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
    {
        if (totalTime <= 0)
        {
            return 0;
        }
        if (i >= cost.size())
        {
            return 1e9;
        }
        if (dp[i][totalTime] != -1)
        {
            return dp[i][totalTime];
        }
        int paidPainter = cost[i] + f(i + 1, totalTime - time[i] - 1, cost, time, dp);
        int freePainter = 0 + f(i + 1, totalTime, cost, time, dp);
        return dp[i][totalTime] = min(paidPainter, freePainter);
    }

public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return f(0, time.size(), cost, time, dp);
    }
};