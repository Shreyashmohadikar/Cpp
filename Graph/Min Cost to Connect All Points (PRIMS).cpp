class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        // {wt, node}
        pq.push({0, 0});
        vector<int> vis(n, 0);
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;

            if (vis[node] == 1)
                continue;
            vis[node] = 1;
            sum += wt;

            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    int adjX = points[i][0];
                    int adjY = points[i][1];
                    int edW = abs(points[node][0] - adjX) + abs(points[node][1] - adjY);
                    pq.push({edW, i});
                }
            }
        }
        return sum;
    }
};
