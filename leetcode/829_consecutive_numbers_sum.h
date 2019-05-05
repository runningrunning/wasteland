/* int consecutiveNumbersSum(int N) */
/* { */
/*     long n = N * 2; */
/*     int m = sqrt(n); */

/*     int x = 1; */
/*     for (int i = 2; i <= m; i ++) */
/*         if (!((n - i * i + i) % (i << 1))) */
/*             x ++; */

/*     return x; */
/* } */

/* int consecutiveNumbersSum(int N) */
/* { */
/*     int n = N * 2; */
/*     int m = sqrt(n); */

/*     int x = 1; */
/*     for (int i = 2; i <= m; i ++) */
/*     { */
/*         int t = n - i * i + i; */
/*         if (t & 1) */
/*             continue; */
/*         if (!(t % (i << 1))) */
/*             x ++; */
/*     } */
/*     return x; */
/* } */


int consecutiveNumbersSum(int N)
{
    int n = N * 2;
    int m = sqrt(n);

    int x = 1;
    int t = n;
    for (int i = 2; i <= m; i ++)
    {
        t -= (i - 1) * 2;
        if (t & 1)
            continue;
        if (!(t % (i << 1)))
            x ++;
    }
    return x;
}
