// DP with clear mind and optimization in the dp ways !!!!
// clear mind !!!!!
// just like generate permutation??
// how to represent it ??
// find better way to DP this calculation
// have n, found k
// how to optimize !!!
// stupid typo and how to optimize this into simple function
// no recursion !!!

// how to get the calculation

#define MOD 1000000007
long cdp(int n, int k, int** dp)
{
    if (dp[n][k])
        return dp[n][k] - 1;

    if (!k)
    {
        dp[n][0] = 2;
        return dp[n][0] - 1;
    }

    int max = (n - 1) * n / 2;

    if (k >= max)
    {
        dp[n][k] = k == max ? 2 : 1;
        return dp[n][k] - 1;
    }

    int l = n > k ? k : (n - 1);
    long num = 0;

    for (int i = l; i >= 0; i --)
    {
        num += cdp(n - 1, k - i, dp);
        num %= MOD;
    }
    dp[n][k] = num + 1;
    return num;
}

int kInversePairs(int n, int k)
{
    int** dp = malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i < n + 1; i ++)
        dp[i] = calloc(sizeof(int), k + 1);

    // return cdp(n, k, dp);

    dp[1][0] = 1;
    for (int i = 2; i <= n; i ++)
    {
        dp[i][0] = 1;

        int mk = k;
        int max = (i - 1) * i / 2;

        if (mk >= max)
        {
            dp[i][max] = 1; // set max here, not mk
            mk = max - 1;
        }

        long num = 1;

        // printf("i is %d %d %d %d %d.\n", i, max, k, mk, dp[i][mk + 1]);
        for (int j = 1; j <= mk; j ++)
        {
            // int l = i > j ? j : i - 1;
            num += dp[i - 1][j];
            if (j >= i) // only have the most i ones, not n, but the most i ones !!!
                num -= dp[i - 1][j - i];
            dp[i][j] = num % MOD;
            // printf("i %d j %d num %ld %d.\n", i, j, num % MOD, dp[i][j]);
        }
    }

    /* /\* int r = cdp(n, k, dp); *\/ */

    /* out(dp[0], k + 1); */
    /* out(dp[1], k + 1); */
    /* out(dp[2], k + 1); */
    /* out(dp[3], k + 1); */
    /* out(dp[4], k + 1); */

    /* /\* return r; *\/ */

    /* // return cdp(n, k, dp); */
    return dp[n][k];
}


/* class Solution { */
/*  public: */
/* #define MOD 1000000007 */

/*     long cdp(int n, int k, int** dp) */
/*     { */
/*         if (dp[n][k]) */
/*             return dp[n][k] - 1; */

/*         if (!k) */
/*         { */
/*             dp[n][0] = 2; */
/*             return dp[n][0] - 1; */
/*         } */
/*         int max = (n - 1) * n / 2; */
/*         if (k >= max) */
/*         { */
/*             dp[n][k] = k == max ? 2 : 1; */
/*             return dp[n][k] - 1; */
/*         } */

/*         long num = 0; */
/*         for (int i = 0; i < n && i <= k; i ++) */
/*         { */
/*             num += cdp(n - 1, k - i, dp); */
/*             num %= MOD; */
/*         } */
/*         dp[n][k] = num + 1; */
/*         return num; */
/*     } */

/*     int kInversePairs(int n, int k) { */
/*         int** dp = (int**)malloc(sizeof(int*) * (n + 1)); */
/*         for (int i = 0; i < n + 1; i ++) */
/*             dp[i] = (int*)calloc(sizeof(int), k + 1); */
/*         int r = cdp(n, k, dp); */
/*         for (int i = 0; i < n + 1; i ++) */
/*             free(dp[i]); */
/*         free(dp); */
/*         return r; */
/*     } */
/* }; */
