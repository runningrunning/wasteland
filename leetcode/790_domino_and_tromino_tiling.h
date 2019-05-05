// 4 is 11 is has L - L (reverse L) solution !!!!
int nts(int n, int* t)
{
    if (t[n])
        return t[n];

    long a = 0;

    if (n >= 1)
        a += nts(n - 1, t);

    if (n >= 2)
        a += nts(n - 2, t);

    if (n >= 3)
    {
        for (int i = 3; i <= n; i += 2)
            a += 2 * nts(n - i, t);
    }

    if (n >= 4)
    {
        for (int i = 4; i <= n; i += 2)
            a += 2 * nts(n - i, t);
    }

    t[n] = a % (1000000000 + 7);
    return t[n];
}

int numTilings(int N)
{
    if (!N)
        return 0;

    int t[1024] = {0};
    t[0] = 1;
    return nts(N, t);
}
