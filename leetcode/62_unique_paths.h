void _up(int m, int n, int x, int y, int* num, int* max)
{
    if (m == x && n == y)
    {
        if ((*num) < max)
            max = *num;
    }

    if (m != x)
        _up(m + 1, n, x, y, num);

    if (n != y)
        _up(m, n + 1, x, y, num);
}

int uniquePaths_2(int m, int n)
{
    int num = 0;
    int max = INT_MAX;
    _up(0, 0, m - 1, n - 1, &num, &max);
    return num;
}

int uniquePaths(int m, int n)
{
    int t = m;

    if (m == 1 || n == 1)
        return 1;

    /* if (m > n) */
    /* { */
    /*     m = n; */
    /*     n = t; */
    /* } */

    if (m == 2)
        return n;

    int* all = malloc(sizeof(int) * m * n);

    for (int i = 0; i < n; i ++)
    {
        all[i] = 1;
        all[n + i] = i + 1;
    }

    for (int i = 2; i < m; i ++)
    {
        all[i * n + i] = 2 * all[(i - 1) * n + i];

        for (int j = i + 1; j < n; j ++)
            all[i * n + j] = all[i * n + j - 1] + all[(i - 1) * n + j];
    }
    return all[m * n - 1];
}
