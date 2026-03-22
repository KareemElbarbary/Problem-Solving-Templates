#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define ll long long
#define sz(x) (int)x.size()

vector<vector<int>> adj, adj1, adj2;
vector<int> dfn, lowlink, comp, vis;
set<pair<int, int>> st;
int ndfn, cn;

void Bridges(int u, int parent) {
    dfn[u] = lowlink[u] = ndfn++;

    for (auto v : adj[u]) {
        if (dfn[v] == -1) {
            Bridges(v, u);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (v != parent) {
            lowlink[u] = min(lowlink[u], dfn[v]);
        }
    }

    if (lowlink[u] == dfn[u] && parent != -1) {
        st.insert({parent, u});
    }
}

void DFS1(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    comp[u] = cn;

    for (auto v : adj1[u]) {
        if (!vis[v]) DFS1(v);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj = adj1 = adj2 = vector<vector<int>> (n + 1);
    dfn = comp = vector<int> (n + 1, -1);
    lowlink = vis = vector<int> (n + 1, 0);
    vector<pair<int, int>> temp;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        temp.push_back({u, v});
    }

    for (int i = 1; i <= n; i++) {
        if (dfn[i] == -1) Bridges(i, -1);
    }

    // Building Graph Without Bridges
    for (int i = 0; i < sz(temp); i++) {
        int u = temp[i].first, v = temp[i].second;
        if (st.count({u, v}) || st.count({v, u})) continue;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cn++;
            DFS1(i);
        }
    }

    // Building Componentes
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int k = adj[i][j], w = adj[i][j];
            if (comp[i] != comp[k]) {
                adj2[comp[i]].push_back(comp[k]);
                adj2[comp[k]].push_back(comp[i]);
            }
        }
    }

}

int32_t main() {
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}