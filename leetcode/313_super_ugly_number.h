void p_heap(long* hp, int hi, int hs, long v)
{
    hp[hi] = v;

    if (hi == 0)
        return;

    while (hi > 0)
    {
        int p = (hi - 1) / 2;

        if ((hp[p] & 0xFFFFFFFF) > (hp[hi] & 0xFFFFFFFF))
        {
            hp[hi] = hp[p];
            hp[p] = v;
        }
        hi = p;
    }
}

long r_heap(long* hp, int hi, int hs)
{
    if (!hi)
        return 0;

    long r = hp[0];

    hi --;

    hp[0] = hp[hi];
    long o = hp[0];
    long v = o & 0xFFFFFFFF;

    int s = 0;
    while (s * 2 + 1 < hi)
    {
        long l = hp[s * 2 + 1] & 0xFFFFFFFF;
        long r = l;

        if (s * 2 + 2 < hi)
            r = hp[s * 2 + 2] & 0xFFFFFFFF;

        if (l <= r)
        {
            if (v < l)
                break;

            hp[s] = hp[s * 2 + 1];
            hp[s * 2 + 1] = o;
            s = s * 2 + 1;
        }
        else
        {
            if (v < r)
                break;

            hp[s] = hp[s * 2 + 2];
            hp[s * 2 + 2] = o;
            s = s * 2 + 2;
        }
    }
    return r;
}

// heap !
int nthSuperUglyNumber(int n, int* primes, int primesSize)
{
    if (n == 1)
        return 1;

    int hi = 0;
    int hs = 2048;
    long* hp = malloc(sizeof(long) * hs);

    -- n;

    int r;
    p_heap(hp, hi ++, hs,  primes[0]);

    while (n --)
    {
        long t = r_heap(hp, hi --, hs);
        long i = (t >> 32) & 0xFFFF;
        long bi = (t >> 48) & 0xFFFF;
        long v = t & 0xFFFFFFFF;
        long b = v / primes[i];

        r = v;

        if (i != primesSize - 1)
        {
            long nv = b * primes[i + 1];
            if (nv < 0x7FFFFFFF)
            {
                if (hi + 1 == hs)
                {
                    hs += 2048;
                    hp = realloc(hp, sizeof(long) * hs);
                }
                t = ((i + 1) << 48) | (i + 1) << 32 | nv;
                p_heap(hp, hi ++, hs, t);
            }
        }

        long nv = (v * primes[bi]);
        if (nv < 0x7FFFFFFF)
        {
            if (hi + 1 == hs)
            {
                hs += 2048;
                hp = realloc(hp, sizeof(long) * hs);
            }

            t = (bi << 48) + ((bi & 0xFFFF) << 32) + nv;
            p_heap(hp, hi ++, hs, t);
        }
    }
    return r;
}
