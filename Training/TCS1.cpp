#include <bits/stdc++.h>
using namespace std;

int optimize_damage(vector<int> D, vector<int> S, vector<int> C, int B) {
    int n = D.size();
    vector<vector<int>> dp(B+1, vector<int>(n+1, 0));

    for (int i = 1; i <= B; i++) {
        for (int j = 1; j <= n; j++) {
            if (S[j-1] <= i) {
                dp[i][j] = max(dp[i][j-1], dp[i-S[j-1]][j-1] + D[j-1]);
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return dp[B][n];
}

int main() {
    vector<int> D, S, C;
    int B, x;

    // Input
    while (cin >> x) {
        D.push_back(x);
    }
    while (cin >> x) {
        S.push_back(x);
    }
    while (cin >> x) {
        C.push_back(x);
    }
    cin >> B;

    // Output
    cout << optimize_damage(D, S, C, B) << endl;

    return 0;
}
