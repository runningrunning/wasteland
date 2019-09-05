// no recursion ???
// brute force + DP
int comp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

#define DELTA(a, b) (a) > (b) ? ((a) - (b)) : ((b) - (a))

void lsw(int* a, int s, int e, int c, int t, int* min, int** dp)
{
    if (s > e)
        return;

    if (dp[s][c])
        return;

    c += a[s];
    int d = DELTA(t - c, c);
    if (*min > d)
        *min = d;

    if (c < t - c)
        lsw(a, s + 1, e, c, t, min, dp);

    dp[s][c] = 1;

    c -= a[s];
    lsw(a, s + 1, e, c, t, min, dp);
    dp[s][c] = 1;
}

int lastStoneWeightII(int* stones, int stonesSize)
{
    int all = 0;
    for (int i = 0; i < stonesSize; i ++)
        all += stones[i];
    qsort(stones, stonesSize, sizeof(int), comp);

    int** dp = malloc(sizeof(int*) * stonesSize);
    for (int i = 0; i < stonesSize; i ++)
        dp[i] = calloc(sizeof(int), stonesSize * 100 + 1);

    int delta = INT_MAX;
    lsw(stones, 0, stonesSize - 1, 0, all, &delta, dp);
    return delta;
}
