void mpa_sort(int* d, int s, int e, int* p)
{
    if (s >= e)
        return;

    int t;

    if (d[s] > d[e])
    {
        t = d[s];
        d[s] = d[e];
        d[e] = t;

        t = p[s];
        p[s] = p[e];
        p[e] = t;
    }

    if (s + 1 >= e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (d[i] < d[s]) i ++;
        while (d[e] > d[s]) e --;

        if (i >= e)
        {
            t = d[s];
            d[s] = d[e];
            d[e] = t;

            t = p[s];
            p[s] = p[e];
            p[e] = t;
        }
        else
        {
            t = d[i];
            d[i] = d[e];
            d[e] = t;

            t = p[i];
            p[i] = p[e];
            p[e] = t;
        }
    }

    mpa_sort(d, cs, e - 1, p);
    mpa_sort(d, e + 1, ce, p);
}

void mpa_sort_1(int* d, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (d[s] > d[e])
    {
        t = d[s];
        d[s] = d[e];
        d[e] = t;
    }

    if (s + 1 >= e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (d[i] < d[s]) i ++;
        while (d[e] > d[s]) e --;

        if (i >= e)
        {
            t = d[s];
            d[s] = d[e];
            d[e] = t;
        }
        else
        {
            t = d[i];
            d[i] = d[e];
            d[e] = t;
        }
    }

    mpa_sort_1(d, cs, e - 1);
    mpa_sort_1(d, e + 1, ce);
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize)
{
    if (!difficultySize || !profitSize || !workerSize)
        return 0;

    bool sort = false;
    for (int i = 0; !sort && (i < difficultySize - 1); i ++)
        if (difficulty[i] > difficulty[i + 1])
            sort = true;

    if (sort)
        mpa_sort(difficulty, 0, difficultySize - 1, profit);

    int n = 0;
    int all = 0;
    int m = profit[0];

    for (int i = 1; i < difficultySize; i ++)
    {
        if (m < profit[i])
            m = profit[i];

        if (difficulty[i] != difficulty[n])
        {
            n ++;
            difficulty[n] = difficulty[i];
        }
        profit[n] = m;
    }

    sort = false;
    for (int i = 0; !sort && (i < workerSize - 1); i ++)
        if (worker[i] > worker[i + 1])
            sort = true;

    if (sort)
        mpa_sort_1(worker, 0, workerSize - 1);

    int x = -1;
    for (int i = 0; i < workerSize; i ++)
    {
        int w = worker[i];
        while (x < n && w >= difficulty[x + 1])
            x ++;
        if (x >= 0)
            all += profit[x];
    }
    return all;
}
