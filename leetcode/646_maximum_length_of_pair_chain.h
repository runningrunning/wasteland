void flc_sort(int** p, int s, int e)
{
    if (s > e)
        return;

    int t;
    if (p[s][0] > p[e][0] || (p[s][0] == p[e][0] && p[s][1] > p[e][1]))
    {
        t = p[s][0];
        p[s][0] = p[e][0];
        p[e][0] = t;

        t = p[s][1];
        p[s][1] = p[e][1];
        p[e][1] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(p[i][0] < p[s][0] || (p[i][0] == p[s][0] && p[i][1] < p[s][1])) i ++;
        while(p[e][0] > p[s][0] || (p[e][0] == p[s][0] && p[e][1] > p[s][1])) e --;

        if (i >= e)
        {
            t = p[s][0];
            p[s][0] = p[e][0];
            p[e][0] = t;

            t = p[s][1];
            p[s][1] = p[e][1];
            p[e][1] = t;
        }
        else
        {
            t = p[i][0];
            p[i][0] = p[e][0];
            p[e][0] = t;

            t = p[i][1];
            p[i][1] = p[e][1];
            p[e][1] = t;
        }
    }

    flc_sort(p, cs, e - 1);
    flc_sort(p, e + 1, ce);
}

int findLongestChain(int** pairs, int pairRowSize, int pairColSize)
{
    if (pairRowSize <= 1)
        return pairRowSize;

    flc_sort(pairs, 0, pairRowSize - 1);

    int all = 1;
    int ps = pairs[0][0];
    int pe = pairs[0][1];
    for (int i = 1; i < pairRowSize; i ++)
    {
        if (pairs[i][0] == ps)
            continue;

        if (pairs[i][0] > pe)
        {
            all ++;
            ps = pairs[i][0];
            pe = pairs[i][1];
        }

        if (pairs[i][0] > ps && pairs[i][1] < pe)
        {
            ps = pairs[i][0];
            pe = pairs[i][1];
        }
    }
    return all;
}
