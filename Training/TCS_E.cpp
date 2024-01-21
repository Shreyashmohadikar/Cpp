#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string directions = "DLRU";
const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, -1, 1, 0};

bool isValid(int r, int c, int n, const vector<vector<int>>& maze) {
    return r >= 0 && c >= 0 && r < n && c < n && maze[r][c] == 1;
}

void findPath(int r, int c, vector<vector<int>>& maze, int n, vector<string>& ans, string& path) {
    if (r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    maze[r][c] = 0;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (isValid(nr, nc, n, maze)) {
            path += directions[i];
            findPath(nr, nc, maze, n, ans, path);
            path.pop_back();
        }
    }

    maze[r][c] = 1;
}

int main() {
    int m, n;
    cin >> m >> n;

    int T;
    cin >> T;

    vector<vector<int>> maze(m, vector<int>(n, 1));

    for (int t = 0; t < T; ++t) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            for (int i = min(y1, y2); i <= max(y1, y2); ++i) {
                maze[x1][i] = 0;
            }
        } else {
            for (int i = min(x1, x2); i <= max(x1, x2); ++i) {
                maze[i][y1] = 0;
            }
        }
    }

    vector<string> ans;
    string path;

    findPath(0, 0, maze, n, ans, path);

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        int rooms_with_exit = 0;
        int total_rooms = 0;
        for (const string& p : ans) {
            rooms_with_exit += count(p.begin(), p.end(), 'D') + count(p.begin(), p.end(), 'R');
            total_rooms += p.size() + 1;
        }
        int probability = round(static_cast<double>(rooms_with_exit) / total_rooms * 100);
        cout << probability << endl;
    }

    return 0;
}
