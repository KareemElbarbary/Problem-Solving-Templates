#define int int64_t
const int base1 = 131, base2 = 137, mod1 = 1e9 + 7, mod2 = 1e9 + 9, N = 1e6 + 5;
int pow1[N], pow2[N];

void init() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow1[i] = (1LL * pow1[i - 1] * base1) % mod1;
        pow2[i] = (1LL * pow2[i - 1] * base2) % mod2;
    }
}

struct Hashing {
    vector<pair<int, int>> pre;
public:
    Hashing(string s) {
        int h1 = 0, h2 = 0;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i];
            h1 = (1LL * h1 * base1 + x) % mod1;
            h2 = (1LL * h2 * base2 + x) % mod2;
            pre.push_back({h1, h2});
        }
    }
    pair<int, int> get(int l, int r) { // (l & r) -> 0-based
        pair<int, int> ret = pre[r];
        int sz = r - l + 1;
        if (l) {
            --l;
            ret.first = (ret.first - 1LL * pre[l].first * pow1[sz] % mod1 + mod1) % mod1;
            ret.second = (ret.second - 1LL * pre[l].second * pow2[sz] % mod2 + mod2) % mod2;
        }
        return ret;
    }
};