class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node}); // {prob, node}

        vector<double> dist(n, INT_MIN);
        dist[start_node] = 1;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            double dis = it.first;
            int node = it.second;

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                double edW = it.second;
                if (edW * dis > dist[adjNode])
                {
                    dist[adjNode] = edW * dis;
                    pq.push({edW * dis, adjNode});
                }
            }
        }
        if (dist[end_node] == INT_MIN)
            return 0.0;
        return dist[end_node];
    }
};