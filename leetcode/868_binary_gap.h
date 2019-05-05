int binaryGap(int N)
{
    if (N <= 0 || !(N & (N - 1)))
        return 0;

    if (!(N & (N + 1)))
        return 1;

    int m = 0;
    int p = 0;

    while (N)
    {
        if (N & 1)
        {
            if (p > m)
                m = p;
            p = 1;
        }
        else if (p)
            p ++;

        N >>= 1;
    }
    return m;
}
