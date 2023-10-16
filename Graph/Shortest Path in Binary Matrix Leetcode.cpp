class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 1 && grid[0][0] == 0)
        {
            return 1;
        }
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        int dr[] = {-1, -1, -1, 0, +1, +1, +1, 0};
        int dc[] = {-1, 0, +1, +1, +1, 0, -1, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 8; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < n &&
                    grid[newr][newc] == 0 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = dis + 1;

                    if (newr == n - 1 && newc == n - 1)
                    {
                        return dist[newr][newc];
                    }

                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};
// r= -1, -1, -1, 0, +1, +1, +1, 0
// c= -1, 0, +1, +1, +1, 0, -1, -1
