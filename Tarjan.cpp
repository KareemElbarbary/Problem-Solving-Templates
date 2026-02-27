vector<vector<int>> adj, comps, adj1;
vector<int> instk, lowlink, dfn, comp;
stack<int> st;
int ndfn;

void tarjan(int u) {
    dfn[u] = lowlink[u] = ndfn++;
    instk[u] = 1;
    st.push(u);
    for (auto v : adj[u]) {
        if (dfn[v] == -1) {
            tarjan(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (instk[v]) {
            lowlink[u] = min(lowlink[u], dfn[v]);
        }
    }

    if (lowlink[u] == dfn[u]) {
        vector<int> temp;
        int node = -1;
        while (node != u) {
            node = st.top();
            st.pop();
            instk[node] = 0;
            temp.push_back(node);
            comp[node] = comps.size();
        }
        comps.push_back(temp);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj = vector<vector<int>> (n + 1);
    dfn = vector<int> (n + 1, -1);
    instk = lowlink = comp = cost = vector<int> (n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    // Convert each component to node - 1 based
    adj1 = vector<vector<int>> (comps.size());
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int k = adj[i][j];
            if (comp[k] != comp[i]) {
                adj1[comp[i]].push_back(comp[k]);
            }
        }
    }
}