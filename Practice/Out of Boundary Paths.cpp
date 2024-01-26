class Solution {
private:
    const int MOD = 1e9 + 7;
    long long solve(int m, int n, int maxMove, int startRow, 
                    int startColumn, vector<vector<vector<int>>> &dp){
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n){
            return 1;
        }
        if(maxMove == 0){
            return 0;
        }
        if(dp[startRow][startColumn][maxMove] != -1){
            return dp[startRow][startColumn][maxMove];
        }
        long long up = solve(m, n, maxMove - 1, startRow - 1, startColumn, dp);
        long long down = solve(m, n, maxMove - 1, startRow + 1, startColumn, dp);
        long long right = solve(m, n, maxMove - 1, startRow, startColumn - 1, dp);
        long long left = solve(m, n, maxMove - 1, startRow, startColumn + 1, dp);
        return dp[startRow][startColumn][maxMove] = (up + down + left + right) % MOD;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1))); 
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};