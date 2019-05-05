int numTrees(int n)
{
    int l = 1;

    int x[32] = { 0, 1, 2, 5,
                  14,0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 0};
    if (n <= 4)
        return x[n];

    for (int i = 3; i <= n; i ++)
    {
        int m = i >> 1;
        int all = x[i - 1];

        for (int j = 1; j < m; j ++)
            all += (x[j] * x[i - 1 - j]);
        all <<= 1;
        if (i & 1)
            all += x[m] * x [m];

        x[i] = all;
    }
    return x[n];
}

/* int numTrees(int n) */
/* { */
/*     int l = 1; */

/*     int x[32] = { 0, 1, 2, 5, */
/*                   14,0, 0, 0, */
/*                   0, 0, 0, 0, */
/*                   0, 0, 0, 0, */
/*                   0, 0, 0, 0, */
/*                   0, 0, 0, 0}; */
/*     if (n <= 4) */
/*         return x[n]; */

/*     for (int i = 3; i <= n; i ++) */
/*     { */
/*         int m = i >> 1; */
/*         int all = x[i - 1] << 1; */

/*         if (i & 1) */
/*             all += x[m] * x [m]; */

/*         for (int j = 1; j < m; j ++) */
/*             all += 2 * (x[j] * x[i - 1 - j]); */
/*         x[i] = all; */
/*     } */
/*     return x[n]; */
/* } */
