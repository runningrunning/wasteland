// try to find better way
// remove duplicates
// try to use sort instead of hash table
// learn a lot about how to use hash map ?
// -1 not possible
int numBusesToDestination(int** routes, int routesRowSize, int *routesColSizes, int S, int T)
{
    if (!routes || !routesRowSize || !routesColSizes || S == T)
        return 0;

    if (routesRowSize == 1)
        return 1;

    int dp = 8209;
    int** rhash = malloc(sizeof(int*) * routesRowSize);

    int f[24] = {0};
    int ft[24] = {0};
    int si = 0;
    int* ss = malloc(sizeof(int) * routesRowSize);

    bool got_des = false;

    for (int i = 0; i < routesRowSize; i ++)
    {
        int* r = routes[i];
        int l = routesColSizes[i];
        rhash[i] = malloc(sizeof(int) * dp);
        memset(rhash[i], 0, sizeof(int) * dp);
        int* hash = rhash[i];

        for (int j = 0; j < l; j ++)
        {
            int x = r[j] % dp;
            while (hash[x] && hash[x] != r[j])
                x = (x + 1) % dp;
            hash[x] = r[j];

            if (r[j] == S && !(ft[i/32] & 1 << (i % 32)))
            {
                ft[i/32] |= 1 << (i % 32);
                ss[si ++] = i;
            }

            if (r[j] == T)
                got_des = true;
        }
    }

    if (!got_des)
    {
        return -1;
    }

    int* af = malloc(sizeof(int) * 31250); // ((1000000 + 31) / 32));
    memset(af, 0, sizeof(int) * 31250);
    af[S / 32] |= 1 << (S % 32);

    int ti = 0;
    int* tt = malloc(sizeof(int) * routesRowSize);

    int step = 1;

    while (true)
    {
        for (int i = 0; i < si; i ++)
        {
            int s = ss[i];

            if (f[s / 32] & (1 << (s % 32)))
                continue;

            f[s/32] |= 1 << (s % 32);

            int* n = routes[s];
            for (int j = 0; j < routesColSizes[s]; j ++)
            {
                int t = n[j];

                if (t == T)
                {
                    return step;
                }

                if (af[t / 32] & (1 << (t % 32)))
                    continue;

                af[t / 32] |= 1 << (t % 32);

                for (int k = 0; k < routesRowSize; k ++)
                {
                    if (ft[k / 32] & (1 << (k % 32)) || k == s)
                        continue;

                    int* hash = rhash[k];

                    int x = t % dp;

                    while (hash[x] && hash[x] != t)
                        x = (x + 1) % dp;

                    if (hash[x] == t)
                    {
                        ft[k/32] |= 1 << (k % 32);
                        tt[ti ++] = k;
                    }
                }
            }
        }

        if (ti == 0)
        {
            return -1;
        }

        int* tmp = ss;
        si = ti;
        ss = tt;
        tt = tmp;
        ti = 0;
        step ++;
    }

    return 0;
}
