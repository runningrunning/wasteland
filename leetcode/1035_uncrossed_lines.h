// seems like dp

int _mul(int** dp, int* a, int as, int ae, int* b, int bs, int be, int* af, int* bf)
{
    if (as > ae || bs > be)
        return 0;

    if (dp[as][bs])
        return dp[as][bs] - 1;

    int max = _mul(dp, a, as + 1, ae, b, bs + 1, be, af, bf);

    if (a[as] == b[bs])
        max += 1;

    int ta = _mul(dp, a, as + 1, ae, b, bs, be, af, bf);
    int tb = _mul(dp, a, as, ae, b, bs + 1, be, af, bf);

    if (max < ta)
        max = ta;
    if (max < tb)
        max = tb;
    dp[as][bs] = max + 1;
    return max;
}

int maxUncrossedLines(int* A, int ASize, int* B, int BSize)
{
    int** dp = malloc(sizeof(int*) * (ASize + 1));
    for (int i = 0; i <= ASize; i ++)
        dp[i] = calloc(sizeof(int), (BSize + 1));

    int* af = calloc(sizeof(int), 2048);
    int* bf = calloc(sizeof(int), 2048);

    for (int i = 0; i < ASize; i ++)
        af[A[i]] = 1;
    for (int i = 0; i < BSize; i ++)
        bf[B[i]] = 1;
    _mul(dp, A, 0, ASize - 1, B, 0, BSize - 1, af, bf);
    return dp[0][0] - 1;
}
