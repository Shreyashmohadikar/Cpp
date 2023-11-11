class Graph
{
private:
    vector<vector<int>> dist;
    int n;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        dist = vector<vector<int>>(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (auto &edge : edges)
        {
            dist[edge[0]][edge[1]] = edge[2];
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge)
    {
        if (dist[edge[0]][edge[1]] <= edge[2])
        {
            return;
        }
        dist[edge[0]][edge[1]] = edge[2];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][edge[0]] + edge[2] + dist[edge[1]][j]);
            }
        }
    }

    int shortestPath(int node1, int node2)
    {
        if (dist[node1][node2] == 1e9)
        {
            return -1;
        }
        return dist[node1][node2];
    }
};