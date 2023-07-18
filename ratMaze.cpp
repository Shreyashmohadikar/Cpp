#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans,
               vector<vector<int>>& vis, string move, int di[], int dj[]) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return true;
        }
        string dir = "DLRU";
        for (int idx = 0; idx < 4; idx++) {
            int nexti = i + di[idx];
            int nextj = j + dj[idx];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
                !vis[nexti][nextj] && m[nexti][nextj] == 1) {
                vis[i][j] = 1;
                if (solve(nexti, nextj, m, n, ans, vis, move + dir[idx], di, dj))
                    return true;
                vis[i][j] = 0;
            }
        }
        return false;
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = { +1, 0, 0, -1 };
        int dj[] = { 0, -1, 1, 0 };
        if (m[0][0] == 1) {
            if (solve(0, 0, m, n, ans, vis, "", di, dj))
                return ans;
        }
        return { "-1" };
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        for (const auto& path : result) {
            cout << path << " ";
        }
        cout << endl;
    }
    return 0;
}

