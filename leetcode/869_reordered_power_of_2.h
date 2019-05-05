bool reorderedPowerOf2(int N)
{
    if (!(N & (N - 1)))
        return true;

    int ni = 0;
    int n[10] = {0};

    while (N)
    {
        ni ++;
        n[N % 10] ++;
        N /= 10;
    }

    int m = 8;

    for (int i = 0; m < 2147483648; i ++)
    {
        m <<= 1;

        int mi = 0;
        int mn = m;
        int ms[10] = {0};

        while (mn)
        {
            mi ++;
            ms[mn % 10] ++;
            mn /= 10;
        }

        if (mi == ni)
        {
            int t = 0;

            for (t = 0; t < 10; t ++)
                if (ms[t] != n[t])
                    break;

            if (t == 10)
                return true;
        }

        if (mi > ni)
            break;
    }

    return false;
}
