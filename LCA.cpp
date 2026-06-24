const int Log = 23;
int anc[N][Log], lvl[N];
vector<vector<int>> adj;

void BuildAncestor(int node, int parent) {
    lvl[node] = lvl[parent] + 1;
    anc[node][0] = parent;
    for (int i = 1; i < Log; i++) {
        int p = anc[node][i - 1];
        anc[node][i] = anc[p][i - 1];
    }
    for (auto v : adj[node]) {
        if (v != parent) BuildAncestor(v, node);
    }
}

int KthAncestor(int node, int k) {
    for (int i = Log - 1; i >= 0; i--) {
        if ((k >> i) & 1) {
            node = anc[node][i];
        }
    }
    return node;
}

int LCA(int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);
    u = KthAncestor(u, lvl[u] - lvl[v]);
    if (u == v) return u;
    for (int i = Log - 1; i >= 0; i--) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

int dis(int u, int v) {
    int lca = LCA(u, v);
    return lvl[u] + lvl[v] - 2 * lvl[lca];
}