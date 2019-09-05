// DP, both optimally
// use recursive is easy to understand
// practice more
int _sgII(int** dp, int i, int m, int* p, int ps)
{
    if (i >= ps)
        return 0;

    if (dp[i][m])
        return dp[i][m];

    if (i + 2 * m >= ps)
    {
        dp[i][m] = p[i];
        return p[i];
    }

    int min = INT_MAX;
    for (int x = 1; x <= m * 2; x ++)
    {
        int t = _sgII(dp, i + x, m > x ? m : x, p, ps);
        if (min > t)
            min = t;
    }

    dp[i][m] = p[i] - min;
    return dp[i][m];
}

int stoneGameII2(int* piles, int pilesSize)
{
    int max = 0;
    int** dp = malloc(sizeof(int*) * pilesSize);
    int m = pilesSize;

    for (int i = pilesSize - 1; i >= 0; i --)
    {
        piles[i] += (i == (pilesSize - 1)) ? 0 : piles[i + 1];
        dp[i] = calloc(sizeof(int), m + 1);
    }

    int x = _sgII(dp, 0, 1, piles, pilesSize);
    return x;
}

int stoneGameII(int* piles, int pilesSize)
{
    int max = 0;
    int m = pilesSize;
    int** dp = malloc(sizeof(int*) * pilesSize);

    for (int i = pilesSize - 1; i >= 0; i --)
    {
        piles[i] += (i == (pilesSize - 1)) ? 0 : piles[i + 1];
        dp[i] = calloc(sizeof(int), m + 1);
    }

    for (int i = pilesSize - 1; i >= 0; i --)
    {
        for (int k = 1; k <= m; k ++)
        {
            if (2 * k >= pilesSize - i)
                dp[i][k] = piles[i];
            else
            {
                int min = INT_MAX;
                dp[i][k] = piles[i];

                for (int q = 1; q <= k * 2 && q <= m; q ++)
                {
                    // how to set M = max(M, X) ? it can just use k < q ? q : k
                    int x = k < q ? q : k;
                    if (min > dp[i + q][x])
                    {
                        min = dp[i + q][x];
                    }
                }
                 dp[i][k] = piles[i] - min;
            }
        }
    }
    return dp[0][1];
}
