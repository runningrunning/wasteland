// NB DIFFERENT SOLUTION !!!!

// why it's hard ? it's MATH & DP
// time limit !!! ???
// how to optimize this code ?
// code optimization
#define _MAX(a, b) (a) > (b) ? (a) : (b)

int _sed(int k, int n, int** c)
{
    if (!n)
        return 0;

    if (c[k][n])
        return c[k][n];

    int max = n;

    int s = 1;
    int e = n;

    while (s < e)
    {
        int m = (s + e) / 2;
        int a = _sed(k - 1, m - 1, c);
        int b = _sed(k, n - m, c);

        if (a == b)
        {
            s = m;
            break;
        }

        if (a < b)
            s = m + 1;
        else
            e = m;
    }

    /* for (int i = 1; i <= n; i ++) */
    /* { */
    /*     int a = _sed(k - 1, i - 1, c); */
    /*     int b = _sed(k, n - i, c); */

    /*     a = a > b ? a : b; */

    /*     if (max > a) */
    /*     { */
    /*         mi = i; */
    /*         max = a; */
    /*     } */
    /*     else */
    /*     if (a > max) */
    /*         break; */
    /* } */

    int a = _sed(k - 1, s - 1, c);
    int b = _sed(k, n - s, c);

    max = a > b ? a : b;

    // printf("k %d n %d i is %d %d.\n", s, e, max + 1);

    c[k][n] = max + 1;
    return max + 1;
}

int superEggDrop(int K, int N)
{
    if (K == 1)
        return N;

    int** n = malloc(sizeof(int*) * (K + 1));
    for (int i = 0; i <= K; i ++)
        n[i] = calloc(sizeof(int), (N + 1));

    for (int j = 1; j <= N; j ++)
        n[1][j] = j;

    return _sed(K, N, n);
}
