// better solution ???
#define MOD 1000000007
long _k(int** n, int c, int k, int** dp)
{
    if (!k)
        return 1;

    if (c == 5)
        return 0;

    if (dp[c][k])
        return dp[c][k];

    int num = n[c][0];
    int* nx = n[c] + 1;
    long re = 0;

    for (int i = 0; i < n[c][0]; i ++)
    {
        re += _k(n, nx[i], k - 1, dp);
        re %= MOD;
    }

    dp[c][k] = re % MOD;

    return re;
}

// dp also

int knightDialer(int N)
{
    int next_0[] = {2, 4, 6};
    int next_1[] = {2, 6, 8};
    int next_2[] = {2, 7, 9};
    int next_3[] = {2, 4, 8};
    int next_4[] = {3, 3, 9, 0};
    int next_5[] = {0};
    int next_6[] = {3, 1, 7, 0};
    int next_7[] = {2, 2, 6};
    int next_8[] = {2, 1, 3};
    int next_9[] = {2, 4, 2};
    int* next[] = { next_0,next_1,next_2,next_3,next_4,next_5,next_6,next_7,next_8,next_9 };

    int** dp = malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i ++)
        dp[i] = calloc(sizeof(int), N);

    int num = 0;
    for (int i = 0; i < 10; i ++)
    {
        num += _k(next, i, N - 1, dp);
        num %= MOD;
    }

    return num % MOD;
}
