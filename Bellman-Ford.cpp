#define ll long long
struct Edge
{
    int u, v, w;
};

vector<Edge> adj;

ll BellmanFord(int src, int n) 
{
    vector<ll> cost(n + 5, 1e18);
    cost[src] = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) 
    {
        for (auto &k : adj) 
        {
            int u = k.u, v = k.v, w = k.w;

            if (cost[v] > cost[u] + w) 
            {
                cost[v] = cost[u] + w;
                if (i == n - 1) ok = true;
            }
        }
    }

    if (ok) return -1e9;

    return cost[n];
}