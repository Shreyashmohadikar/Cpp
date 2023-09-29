#include <bits/stdc++.h>
int f(int i, int j, vector<vector<int>> &matrix, 
        vector<vector<int>> &dp) {
  if (j < 0 || j >= matrix[0].size()) {
    return -1e8;
  }
  if (i == 0) {
    return matrix[0][j];
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int up = matrix[i][j] + f(i - 1, j, matrix, dp);
  int upleft = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
  int upright = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
  return dp[i][j] = max(up, max(upleft, upright));
}
int getMaxPathSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int maxi = -1e8;
  vector<vector<int>> dp(n, vector<int>(m, -1));
  for (int j = 0; j < m; j++) {
    maxi = max(maxi, f(n - 1, j, matrix, dp));
  }
  return maxi;
}
