void PrimeFactor(int n)
{
    for (int i = 2; i * i <= n && n != 1; i++)
    {
        while(n % i == 0)
        {
            cout << i << ' ';
            n /= i;
        }
    }
    if (n != 1) cout << n;
    cout << '\n';
}