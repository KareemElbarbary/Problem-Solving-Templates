struct SparseTable {
    vector<vector<int>> st;

    int merge(int a, int b) {
        return min(a, b);
    }

    SparseTable(vector<int>& a) {
        int n = a.size();
        int LOG = __lg(n) + 1;

        st.assign(LOG, vector<int>(n));
        st[0] = a;

        for (int k = 1; k < LOG; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                st[k][i] = merge(st[k - 1][i],
                                 st[k - 1][i + (1 << (k - 1))]);
    }

    int query(int l, int r) {
        int k = __lg(r - l + 1);
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }
};