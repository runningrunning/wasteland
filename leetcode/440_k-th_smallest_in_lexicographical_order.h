int fkn(long n, int k, int a, int* ns, int ni, long c)
{
    if (ni == 0)
    {
        k --;
        while (k && (c * 10) <= n)
        {
            k --;
            c *= 10;
        }
        return c + k;
    }

    int* t = malloc(sizeof(int) * 10);
    memset(t, 0, sizeof(int) * 10);

    int all = a;
    int o = ns[ni];
    int s = c == 0 ? 1 : 0;
    if (c)
    {
        k -= 1;
        all -= 1;

        if (!k)
            return c;
    }

    for (int i = s; i < 10; i ++)
    {
        int num = 0;
        if (i != o)
        {
            long x = c * 10 + i;
            int y = 1;
            num += y;

            while (x * 10 + 9 < n)
            {
                y *= 10;
                num += y;
                x = x * 10 + 9;
            }
            all -= num;
            t[i] = num;
        }
    }
    t[o] = all;

    for (int i = s; i < 10; i ++)
    {
        if (k > t[i])
            k -= t[i];
        else
            return fkn(n, k, t[i], ns, -- ni, c * 10 + i);
    }
    return 0;
}

int findKthNumber(int n, int k)
{
    if (n < 10 || k == 1)
        return k;

    int o = n;
    int ns[16] = {0};

    int oi = 0;
    while (o)
    {
        ns[oi ++] = o % 10;
        o = o / 10;
    }
    oi --;
    return fkn(n, k, n, ns, oi, 0);
}

/*
int findKthNumber_1(int n, int k) {

    int c = 1;
    int t = n / 10;
    for (int i = 0; i < k - 1; i ++)
    {
        if (c <= t)
            c *= 10;
        else
        {
            if (c == n)
                c /= 10;
            c ++;
            while (!(c % 10))
                c /= 10;
        }
    }
    return c;
}
*/
