void fbp_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    fbp_sort(n, cs, e - 1);
    fbp_sort(n, e + 1, ce);
}

int findBlackPixel(char** picture, int pictureRowSize, int pictureColSize, int N)
{
    if (!N)
        return 0;

    // hash primer
    int h = 8388617;

    int ci = 0;
    int* rs = calloc(sizeof(int), pictureRowSize);
    int* cs = calloc(sizeof(int), pictureColSize);

    for (int i = 0; i < pictureRowSize; i ++)
        for (int j = 0; j < pictureColSize; j ++)
        {
            int r = rs[i] >> 8;
            int rn = rs[i] & 0xFF;

            int c = cs[j] >> 8;
            int cn = cs[j] & 0xFF;

            char x = picture[i][j];

            if (x == 'B')
            {
                rn ++;
                cn ++;
            }

            r = ((r * 100) + x) % h;
            c = ((c * 100) + x) % h;

            rs[i] = r << 8 | rn;
            cs[j] = c << 8 | cn;
        }

    for (int i = 0; i < pictureColSize; i ++)
        if ((cs[i] & 0xFF) == N)
            cs[ci ++] = (cs[i] & 0xFFFFFF00) | i;

    for (int i = 0; i < pictureRowSize; i ++)
        if ((rs[i] & 0xFF) != N)
            rs[i] = 0;

    fbp_sort(cs, 0, ci - 1);

    int num = 0;

    int ti = 0;
    int t[200];
    for (int i = 0; i < ci; i ++)
    {
        int x = cs[i] & 0xFFFFFF00;
        int y = cs[i] & 0xFF;

        ti = 0;
        t[ti ++] = cs[i] & 0xFF;

        while ((i + 1) < ci && (cs[i + 1] & 0xFFFFFF00) == x)
        {
            i ++;
            t[ti ++] = cs[i] & 0xFF;
        }

        bool use = true;

        int pre = -1;

        for (int j = 0; j < pictureRowSize; j ++)
            if (picture[j][y] == 'B')
            {
                if (!rs[j])
                    use = false;

                if (pre == -1)
                    pre = rs[j];
                else if (pre != rs[j])
                    use = false;
                rs[j] = 0;
            }

        if (use)
            num += ti * N;
    }
    return num;
}
