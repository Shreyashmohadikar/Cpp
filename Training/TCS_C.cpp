// Traffic Flow
// Problem Description
// A traffic flow grid is a conceptual representation used in transportation planning and traffic engineering to model and analyze the movement of vehicles through a network of intersections in the city called as junctions. A traffic flow grid is akin to a matrix, with rows and columns denoting various junctions, and matrix cell values symbolizing the traffic flow in that junction. In the era of screens and swipes, traffic's stage can be seen on mobile!

// Srihan finds himself caught in traffic on his way to the workplace. To speed up his journey, he opts to assess the traffic flow grid and chooses a quicker route. He currently resides at coordinates (i, j), and his office is located at coordinates (a, b) in the traffic grid. Given a rule that from a given junction, he can only go to right or down junction (junction is a cell, in terms of matrix). Could you assist him in finding a faster route to reach his workplace?

// Constraints
// Note that the provided positions in the input are indexed starting from 1, where left top is (1, 1).

// 1 <= n, m <= 100

// 0 <= traffic flow <= 10^3

// Input
// First line consists of two space separated integers n, m denoting the number of rows and columns in the traffic grid.

// Next n lines consists of m space separated integers denoting the traffic flow. The value at i, j indicates the traffic flow at junction i and j.

// Line n+2 consists of two space separated integers denoting the coordinates of Srihan's current position.

// Line n+3 consists of two separated integers denoting the coordinates of Srihan's workplace.

// Output
// Single integer denoting the the minimum traffic flow Srihan must navigate to reach his workplace. In case there is no path from his current location to workplace, print "-1".

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 4 4

// 3 1 9 2

// 12 3 10 1

// 11 10 14 2

// 5 4 3 7

// 1 2

// 4 4

// Output

// 22

// Explanation

// Srihan will choose the path - (1,2) -> (1,3) -> (1,4) -> (2,4) -> (3,4) -> (4,4)

// The total traffic flow Srihan navigated is 1 + 9 + 2 + 1 + 2 + 7 = 22 which is the minimum possible.

// Example 2

// Input

// 3 3

// 6 9 1

// 4 7 3

// 5 0 2

// 1 1

// 3 3

// Output

// 17

// Explanation

// Srihan will choose the path - (1,1) -> (2,1) -> (2,2) -> (3,2) -> (3,3)

// The total traffic flow Srihan navigated is 6 + 4 + 5 + 0 + 2 = 17 which is the minimum possible.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(int rows, int cols, vector<vector<int>>& grid, int startRow, int startCol, int endRow, int endCol) {
    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
    dp[startRow - 1][startCol - 1] = grid[startRow - 1][startCol - 1];

    for (int i = startRow - 1; i < endRow; ++i) {
        for (int j = startCol - 1; j < endCol; ++j) {
            if (i > startRow - 1) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
            }
            if (j > startCol - 1) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
    }

    if (dp[endRow - 1][endCol - 1] != INT_MAX) {
        return dp[endRow - 1][endCol - 1];
    } else {
        return -1;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    int startRow, startCol, endRow, endCol;
    cin >> startRow >> startCol >> endRow >> endCol;

    cout << solve(rows, cols, grid, startRow, startCol, endRow, endCol) << endl;

    return 0;
}
