class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> price(n, 1e9), tempPrice(n, 1e9);
        price[src] = 0;
        for (int i = 0; i < k + 1; i++)
        {
            for (auto &it : flights)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (price[u] + wt < tempPrice[v])
                {
                    tempPrice[v] = price[u] + wt;
                }
            }
            for (int i = 0; i < n; i++)
                price[i] = tempPrice[i];
        }
        if (price[dst] == 1e9)
            return -1;
        return price[dst];
    }
};