double myPow(double x, int n)
{
    double extra = 1.0;
    int p = abs(n);

    if (n == INT_MIN)
    {
        p = INT_MAX;
        extra = x;
    }

    if (p == 0)
        return 1;

    if (p == 1)
        return n > 0 ? x : 1.0 / x;

    if (x == 1.0)
        return 1.0;

    double ret = extra;
    double dt = x;

    if (p & 1)
        ret *= x;

    int i = 0;
    int t = p >> 1;
    while(t)
    {
        dt*= dt;
        if (t & 1)
            ret *= dt;
        t >>= 1;
        printf("%x i %d.\n", t, i++);
    }

    return n > 0 ? ret : 1.0 / ret;
}
