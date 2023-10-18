class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> adj[n + 1];
        vector<int> indegree(n + 1, 0);
        for (auto &it : relations)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        vector<int> dist(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                dist[i] = time[i - 1];
            }
        }

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int node = q.front();
                q.pop();
                for (auto &it : adj[node])
                {
                    dist[it] = max(dist[it], dist[node] + time[it - 1]);
                    indegree[it]--;
                    if (indegree[it] == 0)
                    {
                        q.push(it);
                    }
                }
            }
        }
        int maxTime = 0;
        for (auto &it : dist)
        {
            maxTime = max(maxTime, it);
        }
        return maxTime;
    }
};