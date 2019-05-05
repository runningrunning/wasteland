int lastRemaining(int n)
{
    int e = n;
    int s = 1;
    int o = 1;
    int b = 1;
    int x = s;
    while (s != e)
    {
        if (x & b)
        {
            s &= ~b;
            if (!s)
                s |= b << 1;

            if (s > n)
                return s - (b << 1);
        }
        else
        {
            s |= b;
        }
        b <<= 1;
        e = ((n - s) & ~(b - 1)) + s;
        if (o)
            x = e;
        else
            x = s;
        o = !o;
    }
    return s;
}
