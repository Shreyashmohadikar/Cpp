class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> adj[n];
        int edges = 0;
        // creating graph
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
            {
                adj[i].push_back(leftChild[i]);
                edges++;
            }
            if (rightChild[i] != -1)
            {
                adj[i].push_back(rightChild[i]);
                edges++;
            }
        }

        vector<int> indegree(n, 0);
        vector<int> vis(n, 0);
        queue<int> q;
        int cnt = 0; // connected nodes

        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                cnt++;
            }
            if (indegree[i] > 1)
            {
                return false;
            } // for validity of Binary Tree
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (!vis[it] && indegree[it] == 0)
                {
                    q.push(it);
                    cnt++;
                }
            }
        }

        if (cnt != n || edges != n - 1)
        {
            return false;
        }
        return true;
    }
};