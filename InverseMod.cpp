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