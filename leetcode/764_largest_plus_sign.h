// FORGET TO INIT MEMORY!!!
void oo_sort(int* n, int s, int e)
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

    oo_sort(n, cs, e - 1);
    oo_sort(n, e + 1, ce);
}

int oo_bsl(int* n, int l, int p, int a)
{
    int s = 0;
    int e = l - 1;

    if (n[s] == p || n[e] == p)
        return 0;

    if (n[s] > p)
    {
        int t = p < (n[s] - 1 - p) ? p : (n[s] - 1 - p);
        return 1 + t;
    }
    else if (p > n[e])
    {
        int t = (a - 1 - p) < (p - 1 - n[e]) ? (a - 1 - p) : (p - 1 - n[e]);
        return 1 + t;
    }
    else
    {
        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (n[m] < p)
                s = m + 1;
            else
                e = m;
        }
    }
    if (n[s] == p)
        return 0;

    int t = (p - 1 - n[s - 1]) < (n[s] - 1 - p) ? (p - 1 - n[s - 1]) : (n[s] - 1 - p);
    return 1 + t;
}

int orderOfLargestPlusSign(int N, int** mines, int minesRowSize, int *minesColSizes)
{
    int rl[500] = {0};
    int cl[500] = {0};

    int** r = malloc(sizeof(int*) * 500);
    int** c = malloc(sizeof(int*) * 500);

    for (int i = 0; i < minesRowSize; i ++)
    {
        int x = mines[i][0];
        int y = mines[i][1];

        if (!rl[x])
        {
            rl[x] = 1;
            r[x] = malloc(sizeof(int));
            r[x][0] = y;
        }
        else
        {
            rl[x] ++;
            r[x] = realloc(r[x], sizeof(int) * rl[x]);
            r[x][rl[x] - 1] = y;
        }

        if (!cl[y])
        {
            cl[y] = 1;
            c[y] = malloc(sizeof(int));
            c[y][0] = x;
        }
        else
        {
            cl[y] ++;
            c[y] = realloc(c[y], sizeof(int) * cl[y]);
            c[y][cl[y] - 1] = x;
        }
    }

    for (int i = 0; i < 500; i ++)
    {
        if (r[i])
            oo_sort(r[i], 0, rl[i] - 1);

        if (c[i])
            oo_sort(c[i], 0, cl[i] - 1);
    }

    int q = (N + 1) / 2;
    int m = 0;

    for (int i = (N - 1) / 2; i >= 0; i --)
    {
        int e = N - i - 1;

        if (i == e)
        {
            if (!r[i] && !c[i])
                return q;
            else
            {
                int x = q;
                int y = q;

                if (r[i])
                    x = oo_bsl(r[i], rl[i], i, N);

                if (x && c[i])
                    y = oo_bsl(c[i], cl[i], i, N);
                m = x < y ? x : y;
            }
        }
        else
        {
            int x, y, t;
            for (int j = i; j <= e; j ++)
            {
                x = q; y = q;

                if (rl[i])
                    x = oo_bsl(r[i], rl[i], j, N);
                if (x && cl[j])
                    y = oo_bsl(c[j], cl[j], i, N);
                t = x < y ? x : y;

                if (t >= q)
                    return q;

                if (t >= m)
                    m = t;

                x = q; y = q;

                if (rl[e])
                    x = oo_bsl(r[e], rl[e], j, N);
                if (x && cl[j])
                    y = oo_bsl(c[j], cl[j], e, N);
                t = x < y ? x : y;

                if (t >= q)
                    return q;

                if (t >= m)
                    m = t;

                x = q; y = q;

                if (rl[j])
                    x = oo_bsl(r[j], rl[j], i, N);
                if (x && cl[i])
                    y = oo_bsl(c[i], cl[i], j, N);

                t = x < y ? x : y;

                if (t >= q)
                    return q;

                if (t >= m)
                    m = t;

                x = q; y = q;

                if (rl[j])
                    x = oo_bsl(r[j], rl[j], e, N);
                if (x && cl[e])
                    y = oo_bsl(c[e], cl[e], j, N);

                t = x < y ? x : y;

                if (t >= q)
                    return q;

                if (t >= m)
                    m = t;
            }
        }

        q --;

        if (q <= m)
            return m;
    }
    return 0;
}
