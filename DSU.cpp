struct DSU 
{
private:
    vector<int> parent, size;
public:
    DSU(int n)
    {
        parent.resize(n + 5);
        size.resize(n + 5, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }
    int getRoot(int u)
    {
        if (u == parent[u]) return u;
        return parent[u] = getRoot(parent[u]);
    }
    bool sameSet(int u, int v)
    {
        return getRoot(u) == getRoot(v); 
    }
    void merge(int u, int v)
    {
        u = getRoot(u);
        v = getRoot(v);
        if (u == v) return;
        if (size[u] > size[v]) swap(u, v);
        parent[u] = v;
        size[v] += size[u];
    }
};