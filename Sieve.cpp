vector <bool> sieve(int N)
{
    vector<bool> v(N,true);
    v[0] = v[1] = false;
    for (ll i = 2; i * i <= N; i++)
    {
        if (v[i])
        {
            for (ll j = i * i; j <= N; j += i) v[j] = false;
        }
    }
    return v;
}