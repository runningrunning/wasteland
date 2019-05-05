// math ????
// prime way to do so
// at most 63 of 1 as it's 3 to 10 ^ 18
//
//
/* bool _is(long x, long n) */
/* { */
/*     if ((x % n) != 1) */
/*         return false; */

/*     return x == 1 || _is((x - 1) / n, n); */
/* } */
/* long sgb(long x, long n, long* z) */
/* { */
/*     for (long i = *z; i <= n; i ++) */
/*     { */
/*         if (n % i) */
/*             *z = (i + 1); */
/*         else */
/*         { */
/*             *z = i; */
/*             if (_is(n / i, i)) */
/*                 return i; */
/*             else */
/*                 *z = (i + 1); */
/*         } */
/*     } */
/*     return 0; */
/* } */

/* long smallestGoodBase(char* n) */
/* { */
/*     long x = 0; */

/*     int i = 0; */
/*     int c = n[i ++]; */

/*     while (c) */
/*     { */
/*         x = x * 10 + c - '0'; */
/*         c = n[i ++]; */
/*     } */

/*     long z = 2; */
/*     long y = sgb(x, x - 1, &z); */
/* } */

/* long sgb(long x, long u, int l, long* tmp) */
/* { */
/*     if (x == 1) */
/*         return 1; */
/*     if (tmp[l] <= x) */
/*         return 0; */
/*     printf("%ld %ld\n", x, u); */

/*     for (int i = u - 1; i >= 1; i --) */
/*     { */
/*         if (!(x % i)) */
/*             continue; */
/*         long n = x / i; */
/*         if (sgb(i, sqrt(i))) */
/*             return i; */
/*     } */
/*     tmp[l] = x; */
/*     return 0; */
/* } */

long _base(long x, long n, long b)
{
    long s = 3;
    long e = b;

    if (x <= (1L << n) - 1)
        return 0;

    while (s < e)
    {
        long m = (s + e) / 2;
        long t = 1;

        // printf("m %ld %ld %ld\n", m, s, e);

        for (int i = 1; i < n; i ++)
        {
            if (x / m < t)
            {
                t = x + 1;
                break;
            }
            t = t * m + 1;
        }

        if (t == x)
        {
            return m;
        }

        if (t < x)
            s = m + 1;
        else
            e = m;
    }
    return - s;
}

char* smallestGoodBase(char* n)
{
    long x = 0;
    int i = 0;
    long c = n[i ++];
    long tmp[32] = {0};
    while (c)
    {
        x = x * 10 + c - '0';
        c = n[i ++];
    }

    if (!(x & (x + 1)))
        return strdup("2");

    c = x - 1;
    long ret = c;

    for (int i = 3; i < 63; i ++)
    {
        long z = _base(x, i, c);

        if (z > 0)
            ret = z;

        c = z > 0 ? z : -z;
    }

    char* r = malloc(26);
    sprintf(r, "%ld", ret);
    return r;
}

/* long smallestGoodBase2(long x) */
/* { */
/*     long c = x - 1; */
/*     long ret = c; */

/*     for (int i = 3; i < 63; i ++) */
/*     { */
/*         long z = _base(x, i, c); */

/*         if (z > 0) */
/*             ret = z; */

/*         c = z > 0 ? z : -z; */
/*     } */
/*     return ret; */
/* } */

