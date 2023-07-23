#include <vector>
using namespace std;

class Solution {
public:
    // Recursive function to find the maximum cherries collected by both robots
    // i: current row index
    // j1, j2: column indices of the first and second robot, respectively
    // grid: the field of cherries
    // r, c: number of rows and columns in the grid
    // dp: 3D DP array to store computed results for memoization
    int f(int i, int j1, int j2, vector<vector<int>>& grid, int r, int c, vector<vector<vector<int>>>& dp) {
        // Base case: if any robot goes out of bounds, return a large negative value
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
            return -1e8;
        }

        // Base case: if we reach the bottom row, return the cherries at this position
        if (i == r - 1) {
            if (j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        // If the result for this position is already computed, return it
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }


        // Calculate the cherries picked up by both robots at this position
        int cherries = 0;
        if (j1 == j2) {
            cherries = grid[i][j1];
        } else {
            cherries = grid[i][j1] + grid[i][j2];
        }

        // Initialize a variable to keep track of the maximum cherries collected from this position
        int maxi = -1e8;

        // Loop through all possible moves for both robots in the next row
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                // Calculate the total cherries collected by both robots in the next row
                int value = cherries + f(i + 1, j1 + dj1, j2 + dj2, grid, r, c, dp);
                // Update the maximum cherries collected from this position
                maxi = max(maxi, value);
            }
        }

        // Memoize the result and return
        return dp[i][j1][j2] = maxi;
    }

    // Main function to find the maximum cherries collected by both robots from the top-left and top-right corners
    // grid: the field of cherries
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        // Create a 3D DP array with all values initialized to -1 for memoization
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        // Call the recursive function with initial positions for both robots
        return f(0, 0, c - 1, grid, r, c, dp);
    }
};
