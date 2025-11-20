const int N = 1e2, mod = 1e9 + 7;
// Ncr With Pascal ----------------------->
int ncr_pas[N][N] = {};
void ncr_pascal()
{
    ncr_pas[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        ncr_pas[i][0] = 1;
        for (int j = 1; j < N; j++) 
            ncr_pas[i][j] = ncr_pas[i - 1][j] + ncr_pas[i - 1][j - 1]; 
    }
}


// Preprocesse Fact & Inverse Fact ---------->
int PowerMOD(int n, int p, int mod)
{
    if (!p) return 1;
    int a = PowerMOD(n, p / 2, mod) % mod;
    a *= a;
    a %= mod;
    if (p & 1) return (a * (n % mod)) % mod;
    else return a;
}

int inv(int x)
{
    return PowerMOD(x, mod - 2, mod);
}

int fact[N], invfact[N];
void pre()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % mod;

    invfact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; ~i; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
}

// NPR --------------------------->

int NPR(int n, int r)
{
    return fact[n] * invfact[n - r] % mod;
}

// NCR --------------------------->

int NCR(int n, int r)
{
    return fact[n] * invfact[n - r] % mod * invfact[r] % mod;
}