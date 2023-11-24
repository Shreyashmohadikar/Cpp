#include<bits/stdc++.h>
using namespace std;

vector<int> expertise;
vector<vector<int>> conflict;
vector<int> dp;

int solve(int mask) {
    if(mask == 0) return 0;
    if(dp[mask] != -1) return dp[mask];
    int ans = 0;
    for(int i = 0; i < expertise.size(); i++) {
        if(mask & (1 << i)) {
            bool canTake = true;
            for(int j = 0; j < expertise.size(); j++) {
                if(i != j && (mask & (1 << j)) && conflict[i][j]) {
                    canTake = false;
                    break;
                }
            }
            if(canTake) {
                ans = max(ans, expertise[i] + solve(mask ^ (1 << i)));
            }
        }
    }
    return dp[mask] = ans;
}

int main() {
    int n, c;
    cin >> n >> c;
    expertise.resize(n);
    conflict.resize(n, vector<int>(n, 0));
    dp.resize(1 << n, -1);
    for(int i = 0; i < c; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        conflict[u][v] = conflict[v][u] = 1;
    }
    for(int &x : expertise) cin >> x;
    cout << solve((1 << n) - 1) << "\n";
    return 0;
}
