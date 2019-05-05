/* // TODO Better algorithm */
// think about overflow here INT_MAX for bits and s
int countPrimes(int n)
{
    if (n <= 2)
        return 0;
    /* int* fgs = malloc(sizeof(int) * ((n / 32) + 1)); */
    /* memset(fgs, 0xFFFFFFFF, sizeof(int) * ((n / 32) + 1)); */
    char* fgs = malloc(n);
    bzero(fgs, n);

    /*
    int all = 1;
    int bits = 3;
    int last = sqrt(n) + 1;
    while (bits < n)
    {
        if (!fgs[bits])
        {
            all ++;
            if (bits <= last)
            {
                int s = bits * bits;
                while (s < n)
                {
                    fgs[s] = 1;
                    s += 2 * bits;
                }
            }
        }
        bits += 2;
    }
    */

    int all = n >> 1;
    int bits = 3;
    int last = sqrt(n);

    while (bits <= last)
    {
        if (!fgs[bits])
        {
            int s = bits * bits;
            while (s < n)
            {
                if (!fgs[s])
                {
                    fgs[s] = 1;
                    all --;
                }
                s += 2 * bits;
            }
        }

        bits += 2;
    }

    return all;
}

/*
int countPrimes(int n)
{
    if (n < 2)
        return 0;

    int* fgs = malloc(sizeof(int) * (n + 32) / 32);
    memset(fgs, 0xFFFFFFFF, sizeof(int) * (n + 32) / 32);

    int all = 0;
    int bits = 2;
    while (bits < n)
    {
        int f = bits / 32;
        int o = 1 << (bits % 32);

        if (fgs[f] & o)
        {
            all ++;
            int s = 2 * bits;
            while (s < n)
            {
                int sf = s / 32;
                int so = ~(1 << (s % 32));
                fgs[sf] &= so;
                s += bits;
            }
        }
        bits ++;
    }
    return all;
}
*/
