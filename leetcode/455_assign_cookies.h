void fcc_max_sort(int* n, int s, int e, int u)
{
    if (s >= e)
        return;

    int t;
    if (n[s] < n[e])
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
        while(n[i] > n[s]) i ++;
        while(n[e] < n[s]) e --;

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

    fcc_max_sort(n, cs, e - 1, u);

    if (u > e)
        fcc_max_sort(n, e + 1, ce, u);
}

void fcc_min_sort(int* n, int s, int e, int u)
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
        while(n[i] < n[s]) i ++;
        while(n[e] > n[s]) e --;

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

    fcc_min_sort(n, cs, e - 1, u);

    if (u > e)
        fcc_min_sort(n, e + 1, ce, u);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    if (!gSize || !sSize)
        return 0;

    int ms = gSize < sSize ? gSize : sSize;
    ms -= 1;

    fcc_max_sort(s, 0, sSize - 1, ms);
    fcc_min_sort(g, 0, gSize - 1, ms);

    int si = 0;
    int num = 0;

    for (int i = ms; i >= 0; i --)
    {
        if (s[si] < g[i])
            continue;
        si ++;
        num ++;
    }
    return num;
}
