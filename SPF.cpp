vector<int> sp(N);
void spf()
{
    for (int i = 0; i < N; i++) sp[i] = i;

    for (int i = 2; i < N / i; i++)
    {
        if (sp[i] == i)
        {
            for (int j = i * i; j < N; j += i)
                sp[j] = min(sp[j], i);
        }
    }
}