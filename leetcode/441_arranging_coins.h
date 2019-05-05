int ac(int s, int e, int n)
{
    if (s >= e)
        return e;

    long m = (s + e) >> 1;
    long x = (m + 1) * m / 2;

    if (n >= x)
    {
        if (n - x <= m)
            return m;
        return ac(m + 1, e, n);
    }
    else
        return ac(s, m - 1, n);
}

int arrangeCoins(int n)
{
    long x = (long) n * 2;
    x = sqrtl(x);
    return ac(1, (int)x, n);
}

/*
int a2(int n)
{
    long y = (long) n * 2;
    long x = sqrtl(y);

    while(x * x + x > y)
        x --;
    return (int) x;
}
*/

int a2(int n)
{
    if (n < 1073741824)
    {
        int y = n * 2;
        int x = sqrt(y);
        while(x * x + x > y)
            x --;
        return (int) x;
    }
    else
    {
        long y = (long) n * 2;
        long x = sqrtl(y);
        while(x * x + x > y)
            x --;
        return (int) x;
    }
}
