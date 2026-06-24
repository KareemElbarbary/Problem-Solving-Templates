const int base1 = 131, base2 = 137, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
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
        if (ret.first < 0) ret.first += mod1;
        if (ret.second < 0) ret.second += mod2;
        return ret;
    }
};

class manacher {
private:
    vector<int> d;

public:
    manacher(string t) {
        string s = "#";
        for (auto c : t) {
            s += c + string("#");
        }
        int n = s.size(), l = 1, r = 1;
        s = "$" + s + "^";
        vector<int> p(n + 2);
        for (int i = 1; i <= n; i++) {
            p[i] = max(0ll, min(r - i, p[l + (r - i)]));
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        d = vector<int>(p.begin() + 1, p.end() - 1);
    }

    int even(int i) {
        return d[2 * i] - 1;
    }

    int odd(int i) {
        return d[2 * i + 1] - 1;
    }

    bool is_palindrome(int l, int r) {
        int len = r - l + 1;
        if (len & 1) {
            return odd((l + r) / 2) >= len;
        }
        else {
            return even((l + r) / 2 + 1) >= len;
        }
    }
};

vector<int> Z(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0LL, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }
    return z;
}

vector<int> Kmp(string a) {
    int n = a.size();
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && a[i] != a[j]) j = pi[j - 1];
        if (a[i] == a[j]) j++;
        pi[i] = j;
    }
    return pi;
}