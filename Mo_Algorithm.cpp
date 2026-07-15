const int SQ = 450;

struct query {
    int l, r, idx;
    bool operator<(const query &other) const {
        if (l / SQ != other.l / SQ) return l / SQ < other.l / SQ;
        return (l / SQ & 1 ? r < other.r : r > other.r);
    }
};

void solve() {
    int n, qry; cin >> n >> qry;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    vector<query> q(qry);
    for (int i = 0; i < qry; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
        q[i].l--, q[i].r--;
    }
    
    sort(q.begin(), q.end());
    

    auto add = [&](int idx) {
        // include idx
    };

    auto del = [&](int idx) {
        // remove idx
    };

    auto get = [&]() {
        // current answer
    };

    int l = 0, r = -1;
    vector<int> ans(qry);
    for (auto &[lq, rq, idx] : q) {
        while (l > lq) add(--l);
        while (r < rq) add(++r);
        while (l < lq) del(l++);
        while (r > rq) del(r--);
        ans[idx] = get();
    }


}