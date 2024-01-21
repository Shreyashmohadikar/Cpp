


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min_traffic(int n, int m, vector<vector<int>>& grid, int i, int j, int a, int b) {
    // Initialize the dp table
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[i-1][j-1] = grid[i-1][j-1];

    // Fill the dp table
    for (int x = i-1; x < a; ++x) {
        for (int y = j-1; y < b; ++y) {
            if (x > i-1) {
                dp[x][y] = min(dp[x][y], dp[x-1][y] + grid[x][y]);
            }
            if (y > j-1) {
                dp[x][y] = min(dp[x][y], dp[x][y-1] + grid[x][y]);
            }
        }
    }

    // If the destination cell is reachable, return the minimum traffic flow
    if (dp[a-1][b-1] != INT_MAX) {
        return dp[a-1][b-1];
    } else {
        return -1;
    }
}

int main() {
    // Test the function
    vector<vector<int>> grid1 = {{3, 1, 9, 2}, {12, 3, 10, 1}, {11, 10, 14, 2}, {5, 4, 3, 7}};
    cout << min_traffic(4, 4, grid1, 1, 2, 4, 4) << endl;  // Output: 22

    vector<vector<int>> grid2 = {{6, 9, 1}, {4, 7, 3}, {5, 0, 2}};
    cout << min_traffic(3, 3, grid2, 1, 1, 3, 3) << endl;  // Output: 17

    return 0;
}
