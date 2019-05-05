// clear mind !!!
// peek solution !!!!
// how to generate DP ?
// how to know the different DP here !
// DP and Math ?
// dp ?
// Or just bit operation
// 4 is 5 3
// 5 is 7 AARARAA (how to use DP to get this solution
// and how to optimize this ??
// BFS can also be answer !!!!!, stupid ways !!!!

int _rc(int t, int* dp)
{
    int extra = t < 0 ? 1 : 0;

    if (!t)
        return 0;

    if (t < 0)
        t = - t;

    if (dp[t])
        return dp[t] - 1 + extra;

    int i = 1;
    int n = 1;
    int m = INT_MAX;

    while (n < t)
    {
        // int x = i + 2 + _rc(t - n, dp); // RR, conver by below case
        // if (x < m)
        //     m = x;

        for (int j = 0; j <= i + 1; j ++)
        {
            int b = (1 << (j)) - 1;
            if (n <= b)
                break;
            int x = i + 1 + j + _rc(n - b - t, dp);// R j
            if (x < m)
                m = x;
        }
        n += 1 << (i ++);
    }

    while (n > t)
    {
        if (n - t >= t)
            break;

        int x = i + _rc(t - n, dp); // R b
        if (x < m)
            m = x;
        n += 1 << (i ++);
    }

    dp[t] = m + 1;
    return m + extra;
}

int racecar(int target)
{
    if (!target)
        return 0;

    int i = 1;
    int n = 1;
    while (n < target)
        n += 1 << (i ++);

    if (n == target)
        return i;

    int* dp = calloc(sizeof(int), n + 1);
    for (; i >= 0; i --)
        dp[(1 << i) - 1] = i + 1;

    int x = _rc(target, dp);
    out(dp, n + 1);
    return x;
}
