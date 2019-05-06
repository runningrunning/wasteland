// reverse dp !!! is much faster than no reverse one !
// dp ???? just store the internal value
// how to define triangulate, how to do so
// just divide them
// Find better solution optimize !!!!!

int minScoreTriangulation(int* A, int ASize)
{
    if (ASize < 3)
        return 0;

    if (ASize == 3)
        return A[0] * A[1] * A[2];

    int** dp = malloc(sizeof(int*) * ASize);
    for (int i = 0; i < ASize; i ++)
    {
        dp[i] = calloc(sizeof(int), ASize);
    }

    // reverse dp
    for (int i = 2; i < ASize; i ++)
        for (int j = 0; j < ASize - i; j ++)
        {
            for (int k = j + 1; k < j + i; k ++)
            {
                int t = dp[j][k] + dp[k][j + i] + A[j] * A[k] * A[j + i];
                if (!dp[j][j + i] || dp[j][j + i] > t)
                    dp[j][j + i] = t;

            }
        }

    return dp[0][ASize - 1];
}

int _mst(int* A, int s, int e, int v, int*** dp)
{
    if (dp[v][s][e])
        return dp[v][s][e];

    int min = INT_MAX;

    if (e - s < 1)
        return 0;

    if (e - s == 1)
    {
        dp[v][s][e] = A[s] * A[s + 1] * A[v];
        return A[s] * A[s + 1] * A[v];
    }

    for (int i = s; i < e; i ++)
        for (int j = i + 1; j <= e; j ++)
        {
            int t = A[i] * A[j] * A[v] +
                _mst(A, s, i, v, dp) +
                _mst(A, i + 1, j, i, dp) +
                _mst(A, j, e, v, dp);

            if (t < min)
                min = t;
        }
    dp[v][s][e] = min;
    return min;
}

int minScoreTriangulation1(int* A, int ASize)
{
    if (ASize < 3)
        return 0;

    if (ASize == 3)
        return A[0] * A[1] * A[2];

    int*** dp = malloc(sizeof(int**) * ASize);
    for (int i = 0; i < ASize; i ++)
    {
        dp[i] = malloc(sizeof(int*) * ASize);
        for (int j = 0; j < ASize; j ++)
            dp[i][j] = calloc(sizeof(int), ASize);
    }
    return _mst(A, 1, ASize - 1, 0, dp);
}
/* int _mst(int* A, int s, int e, int v, int** dp) */
/* { */
/*     if (v == 0 && dp[s][e]) */
/*         return dp[s][e]; */

/*     int min = INT_MAX; */

/*     if (v == 0) */
/*     { */
/*         if (e - s == 2) */
/*         { */
/*             dp[s][e] = A[s] * A[s + 1] * A[s + 2]; */
/*             return dp[s][e]; */
/*         } */

/*         if (e - s < 2) */
/*             return 0; */

/*         for (int i = s + 1; i < e; i ++) */
/*             for (int j = i + 1; j <= e; j ++) */
/*             { */
/*                 int t = A[i] * A[j] * A[s] + _mst(A, s, i, 0, dp) + */
/*                     _mst(A, i, j, 0, dp) + _mst(A, j, e, A[s], dp); */

/*                 if (t < min) */
/*                     min = t; */
/*             } */
/*         dp[s][e] = min; */
/*     } */
/*     else */
/*     { */
/*         if (e - s < 1) */
/*             return 0; */

/*         if (e - s == 1) */
/*             return A[s] * A[s + 1] * v; */

/*         for (int i = s; i < e; i ++) */
/*             for (int j = i + 1; j <= e; j ++) */
/*             { */
/*                 int t = A[i] * A[j] * v + */
/*                     _mst(A, s, i, v, dp) + */
/*                     _mst(A, i, j, 0, dp) + */
/*                     _mst(A, j, e, v, dp); */

/*                 if (t < min) */
/*                     min = t; */
/*             } */
/*     } */
/*     return min; */
/* } */

/* int minScoreTriangulation(int* A, int ASize) */
/* { */
/*     if (ASize < 3) */
/*         return 0; */

/*     if (ASize == 3) */
/*         return A[0] * A[1] * A[2]; */

/*     int** dp = malloc(sizeof(int*) * ASize); */
/*     for (int i = 0; i < ASize; i ++) */
/*         dp[i] = calloc(sizeof(int), ASize); */
/*     return _mst(A, 0, ASize - 1, 0, dp); */
/* } */
