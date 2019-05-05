// just recursive ?????
// why even is always 1, but odd is always 0
bool dg(int N, int* dp)
{
    if (dp[N])
        return dp[N] - 1;
    for (int i = 1; i <= sqrt(N); i ++)
    {
        if (N % i)
            continue;
        if (!dg(N - i, dp))
        {
            dp[N] = 1 + 1;
            return dp[N] - 1;
        }
    }
    dp[N] = 0 + 1;
    return dp[N] - 1;
}

// even - 1 = odd
// odd - X = even
// even always win
bool divisorGame(int N)
{
    return !(N % 2);
    /* int* t = calloc(sizeof(int), 1024); */
    /* t[1] = 0 + 1; */
    /* t[2] = 1 + 1; */
    /* t[3] = 0 + 1; */
    /* return dg(N, t); */
}
