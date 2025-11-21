#define int long long 
int countbits(int x)
{
    return __builtin_popcountll(x);
}

//--------------------------------------------

// 0 --> 0
// 1 --> 0
int clearbit(int n, int bit)
{
    return (n & (~(1LL << bit)));
}

//--------------------------------------------


// 1 --> 1
// 0 --> 1
int setbit(int n, int bit)
{
    return (n | (1LL << bit));
}

//--------------------------------------------

// 0 --> 1
// 1 --> 0
int toggleBit(int n, int bit)
{
    return (n ^ (1LL << bit));
}

//--------------------------------------------

// 1 or 0 ??
bool knowBit(int n, int bit)
{
    return (n >> bit) & 1;
}

//--------------------------------------------

bool isPowerOf2(int n)
{
    return (__builtin_popcountll(n) == 1);
}