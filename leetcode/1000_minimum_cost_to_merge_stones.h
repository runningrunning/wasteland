// try every divide, there is similar question, try to find better way ~~~
// try to not use recursive function, is it easy to do so ????
// just DP, but need more careful
// how to represent this DP i to j
// but divide them into k steps is not that easy, it's easy just make sure only
// n % (k - 1) == 1 is possible
// just use dp[i][j] ?? and only n % (k - 1) == 1 can works
// the hard part is how to divide it into K parts

// divide it into K numbers
// effort << 16 | value
// when effort == 0xFFFF means not possible

// do not use recursive ?????, is it possible ?
int _ms(int* n, int s, int e, int K, int** dp);
void _try(int* n, int s, int e, int K, int l, int* t, int **dp)
{
    // printf("_try %d %d.\n", s, e);
    if (l == K - 1)
    {
        t[l] = s << 16 | e;
        // do _calculate
        int effort = 0;
        int value = 0;
        for (int i = 0; i < K; i ++)
        {
            int x = _ms(n, t[i] >> 16, t[i] & 0xFFFF, K, dp);
            if (x == -1)
                return;
            effort += x >> 16;
            value += x & 0xFFFF;
        }

        int os = t[0] >> 16;
        int oe = e;

        if (!dp[os][oe] || (dp[os][oe] > ((effort + value) << 16 | value)))
            dp[os][oe] = (effort + value) << 16 | value;
    }
    else
    {
        int os = s;
        for (s; s <= e - (K - l - 1); s += (K - 1))
        {
            t[l] = os << 16 | s;
            _try(n, s + 1, e, K, l + 1, t, dp);
        }
    }
}

int _ms(int* n, int s, int e, int K, int** dp)
{
    // printf("_ms %d %d.\n", s, e);
    if (dp[s][e])
        return dp[s][e];

    if (s == e)
    {
        dp[s][e] = n[s];
        return dp[s][e];
    }

    if (e - s + 1 == K)
    {
        int r = 0;
        for (int i = s; i <= e; i ++)
            r += n[i];
        return r << 16 | r;
    }

    if (K != 2 && ((e - s + 1) % (K - 1)) != 1)
        return -1;

    int t[31] = {0};
    _try(n, s, e, K, 0, t, dp);
    if (!dp[s][e])
        dp[s][e] = -1;
    return dp[s][e];
}

int mergeStones(int* stones, int stonesSize, int K)
{
    // when it's 1, should be 0 also
    if (!stones || stonesSize < 2)
        return 0;

    if (K != 2 && (stonesSize % (K - 1)) != 1)
        return -1;

    int** dp = malloc(sizeof(int*) * stonesSize);
    for (int i = 0; i < stonesSize; i ++)
        dp[i] = calloc(sizeof(int), stonesSize);

    return _ms(stones, 0, stonesSize - 1, K, dp) >> 16;
}
