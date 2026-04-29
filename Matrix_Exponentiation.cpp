using Row = vector <int>;
using Matrix = vector <Row>;

Matrix mul (Matrix &a, Matrix &b) {
    int n = a.size(), m = b[0].size(), o = a[0].size();
    Matrix res(n, Row(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < o; k++) {
                res[i][j] += (1LL * (a[i][k] % mod) * (b[k][j] % mod)) % mod;
                if (res[i][j] >= mod) res[i][j] -= mod;
                if (res[i][j] < 0) res[i][j] += mod;
            }
        }
    }
    return res;
}

Matrix power (Matrix a, int p) {
    int n = a.size();
    Matrix res(n, Row(n));
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (p) {
        if (p & 1) res = mul(res, a);
        a = mul(a, a), p >>= 1;
    }
    return res;
}