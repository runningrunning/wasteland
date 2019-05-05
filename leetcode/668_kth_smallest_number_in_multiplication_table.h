
int _count(int x, int min, int max)
{
    int c = 0;
    int d = x / max;
    c = d * max;

    for (int i = d; i < min; i ++)
    {
        if (x < i + 1)
            break;
        c += x / (i + 1);
    }
    return c;
}

int findKthNumber(int m, int n, int k)
{
    if (k == 1)
        return 1;

    if (m == 1 || n == 1)
        return k;

    if (m * n == k)
        return k;

    int _min = m > n ? n : m;
    int _max = m > n ? m : n;

    int s = 1;
    int e = k - 1;

    while (s < e)
    {
        int m = s + (e - s) / 2;
        int cm = _count(m, _min, _max);
        if (cm < k)
            s = m + 1;
        else
            e = m;
    }
    return s;
}

/* int _count(int x, int min, int max) */
/* { */
/*     int n = 0; */

/*     if (x <= min) */
/*         n = 2; */
/*     else if (x <= max) */
/*         n = 1; */

/*     int _min = min > x ? x : min; */

/*     for (int i = 2; i <= _min; i++) */
/*     { */
/*         if (i * i > x) */
/*             break; */

/*         if (!(x % i)) */
/*         { */
/*             int y = x / i; */

/*             if (y < i) */
/*                 break; */

/*             if (y == i) */
/*                 n ++; */
/*             else */
/*             { */
/*                 if (y <= min) */
/*                     n += 2; */
/*                 else if (y <= max) */
/*                     n += 1; */
/*             } */
/*         } */
/*     } */
/*     return n; */
/* } */

/* int findKthNumber(int m, int n, int k) */
/* { */
/*     if (k == 1) */
/*         return 1; */

/*     if (m == 1 || n == 1) */
/*         return k; */

/*     if (m * n == k) */
/*         return k; */

/*     int x = 1; */
/*     int i = 1; */

/*     int _min = m > n ? n : m; */
/*     int _max = m > n ? m : n; */

/*     while(i < k) */
/*     { */
/*         x ++; */
/*         i += _count(x, _min, _max); */
/*     } */
/*     return x; */
/* } */

