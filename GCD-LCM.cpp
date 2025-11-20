int LCM(int a, int b)
{
    return a * b / __gcd(a, b);
}




int GCD(int a, int b)
{
    if (b < a) swap(a, b);
    if (a == 0) return b;
    return GCD(b % a, a);
}