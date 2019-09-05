// simple is the fastest !!!!!!
// code optimize !!!!
// dp ?
int _ld(char* t, int s, int e, int l, int** dp)
{
    if (dp[s][e])
        return dp[s][e] - 1;

    if (s == l - e)
    {
        int x = 0;
        int max = 0;

        for (int i = s; i < (l + 1) / 2; i ++)
        {
            x ^= t[i];
            x ^= t[l - i];

            if (!x)
            {
                int z = _ld(t, s, i, l, dp) * 2;
                // printf("z %d %d %d.\n", s, i, z);
                if (z && (l != 2 * i + 1))
                {
                    z += _ld(t, i + 1, l - i - 1, l, dp);
                }
                if (z > max)
                    max = z;
            }
        }
        if (!max)
            max = 1;
        dp[s][e] = max + 1;
        // printf("%d %d %d.\n", s, e, max);

        return max;
    }
    else
    {
        if (s == e)
        {
            dp[s][e] = t[s] == t[l - s] ? 2 : 1;
            return dp[s][e] - 1;
        }
        else
        {
            int x = 0;
            int max = 0;

            for (int i = s; i < e; i ++)
            {
                int x = _ld(t, s, i, l, dp);

                if (x)
                {
                    int y = _ld(t, i + 1, e, l, dp);

                    if (y)
                        x += y;
                    else
                        x = 0;
                }

                if (x > max)
                    max = x;
            }

            // printf("= %d %d %d.\n", s, e, max);
            if (!max)
            {
                bool same = true;

                for (int i = s, j = l - e; i <= e; i ++, j ++)
                {
                    if (t[i] != t[j])
                    {
                        same = false;
                        break;
                    }
                }

                if (same)
                    max = 1;
            }
            dp[s][e] = max + 1;
        }
    }
    return dp[s][e] - 1;
}

int _ld2(char* t, int s, int e, int l, int** dp)
{
    if (dp[s][e])
        return dp[s][e] - 1;

    if (s == l - e)
    {
        if (s == e)
        {
            dp[s][e] = 2;
            return dp[s][e] - 1;
        }

        int os = s;
        int oe = e;
        int max = 0;

        while (s < e)
        {
            int x = _ld2(t, os, s, l, dp) * 2;
            if (s != e - 1 && x)
                x += _ld2(t, s + 1, e - 1, l, dp);

            if (x > max)
                max = x;

            s ++;
            e --;
        }
        s = os;
        e = oe;

        if (!max)
            max = 1;

        // printf("os %d oe %d %d.\n", os, oe, max);
        dp[os][oe] = max + 1;
    }
    else
    {
        if (s == e)
        {
            dp[s][e] = t[s] == t[l - s] ? 2 : 1;
        }
        else
        {
            int x = 0;

            for (int i = s; i <= e; i ++)
            {
                x ^= t[i];
                x ^= t[l - i];
            }

            // printf("s %d %d %d.\n", s, e, x);
            if (x)
            {
                dp[s][e] = 1;
            }
            else
            {
                int max = 0;
                for (int i = s; i < e; i ++)
                {
                    int x = _ld2(t, s, i, l, dp);
                    if (x)
                    {
                        int y = _ld2(t, i + 1, e, l, dp);

                        if (y)
                            x += y;
                        else
                            x = 0;
                    }

                    if (x > max)
                        max = x;
                }

                if (!max)
                {
                    bool same = true;

                    for (int i = s, j = l - e; i <= e; i ++, j ++)
                    {
                        if (t[i] != t[j])
                        {
                            same = false;
                            break;
                        }
                    }

                    if (same)
                        max = 1;
                }
                // printf("%d %d %d.\n", s, e, max);
                dp[s][e] = max + 1;
            }
        }
    }
    return dp[s][e] - 1;
}

int longestDecomposition2(char * text)
{
    int l = strlen(text);
    if (l < 2)
        return l;
    int** dp = malloc(sizeof(int*) * l);
    for (int i = 0; i < l; i ++)
        dp[i] = calloc(sizeof(int), l);
    _ld(text, 0, l - 1, l - 1, dp);
    return dp[0][l - 1] - 1;
}

int _ld3(char* t, int s, int e, int* dp)
{
    if (dp[s])
        return dp[s] - 1;

    int se = s, es = e;
    int x = 0;

    if (s > e)
    {
        dp[s] = 1;
        return 0;
    }

    if (s == e)
    {
        dp[s] = 2;
        return 1;
    }

    int max = 1;
    int xor = 0;
    while (se < es)
    {
        xor ^= t[se];
        xor ^= t[es];
        if (!xor && !strncmp(t + s, t + es, se - s + 1))
        {
            x = _ld3(t, se + 1, es - 1, dp);
            if (max < 2 + x)
                max = 2 + x;
        }
        se ++;
        es --;
    }
    dp[s] = max + 1;
    return max;
}

int longestDecomposition(char * text)
{
    int l = strlen(text);
    int s = 0;
    int e = l - 1;
    int* dp = calloc(sizeof(int), l);
    return _ld3(text, s, e, dp);
}
