class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp){
        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return matrix[i][j];
        if(dp[i][j] != -2) return dp[i][j];

        int up = matrix[i][j] + solve(i-1, j, matrix, n, dp);
        int upLeft = matrix[i][j] + solve(i-1, j-1, matrix, n, dp);
        int upRight = matrix[i][j] + solve(i-1, j+1, matrix, n, dp);

        return dp[i][j] = min({up, upLeft, upRight});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -2));
        int mini = 1e9;
        for(int j = m - 1; j >= 0; j--){
            mini = min(mini, solve(n-1, j, matrix, n, dp));
        }
        return mini;
    }
};