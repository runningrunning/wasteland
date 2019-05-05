int maxIncreaseKeepingSkyline(int** g, int r, int *cs)
{
    if (!g || r < 2 || cs[0] < 2)
        return 0;

    int rh[50] = {0};
    int ch[50] = {0};

    int a = 0;
    for (int i = 0; i < r; i ++)
        for (int j = 0; j < cs[0]; j ++)
        {
            int t = g[i][j];
            a += t;
            if (t > rh[i])
                rh[i] = t;

            if (t > ch[j])
                ch[j] = t;
        }

    int c = 0;
    for (int i = 0; i < r; i ++)
        for (int j = 0; j < cs[0]; j ++)
            c += rh[i] > ch[j] ? ch[j] : rh[i];

    return c - a;
}
