// BFS double
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestAlternatingPaths(int n, int** red_edges, int red_edgesSize, int* red_edgesColSize, int** blue_edges, int blue_edgesSize, int* blue_edgesColSize, int* returnSize)
{
    int** rs = calloc(sizeof(int*), n);
    int** bs = calloc(sizeof(int*), n);

    for (int i = 0; i < red_edgesSize; i ++)
    {
        int* p = red_edges[i];

        int s = p[0];
        int e = p[1];

        if (rs[s])
        {
            rs[s][0] ++;
            rs[s] = realloc(rs[s], sizeof(int) * (rs[s][0] + 1));
        }
        else
        {
            rs[s] = malloc(sizeof(int) * 2);
            rs[s][0] = 1;
        }
        rs[s][rs[s][0]] = e;
    }

    for (int i = 0; i < blue_edgesSize; i ++)
    {
        int* p = blue_edges[i];

        int s = p[0];
        int e = p[1];

        if (bs[s])
        {
            bs[s][0] ++;
            bs[s] = realloc(bs[s], sizeof(int) * (bs[s][0] + 1));
        }
        else
        {
            bs[s] = malloc(sizeof(int) * 2);
            bs[s][0] = 1;
        }
        bs[s][bs[s][0]] = e;
    }

    int* rn = calloc(sizeof(int), n);
    int* bn = calloc(sizeof(int), n);
    int* cn = rn;
    int** cb = rs;

    int* sta = malloc(sizeof(int) * n);
    int* stb = malloc(sizeof(int) * n);

    int si = 0;
    int nsi = 0;
    int* st = sta;
    int* nst = stb;

    st[si ++] = 0;
    int l = 2;
    while (si)
    {
        for (int i = 0; i < si; i ++)
        {
            int s = st[i];
            if (!cb[s])
                continue;

            for (int j = 1; j <= cb[s][0]; j ++)
            {
                int e = cb[s][j];
                if (!cn[e] || cn[e] > l)
                {
                    cn[e] = l;
                    nst[nsi ++] = e;
                }
            }
        }

        l ++;
        si = nsi;
        nsi = 0;
        st = st == sta ? stb : sta;
        nst = nst == sta ? stb : sta;
        cb = cb == rs ? bs : rs;
        cn = cn == rn ? bn : rn;
    }


    si = 0;
    nsi = 0;
    st = sta;
    nst = stb;

    st[si ++] = 0;

    l = 2;
    cn = bn;
    cb = bs;

    while (si)
    {
        for (int i = 0; i < si; i ++)
        {
            int s = st[i];
            if (!cb[s])
                continue;

            for (int j = 1; j <= cb[s][0]; j ++)
            {
                int e = cb[s][j];
                if (!cn[e] || cn[e] > l)
                {
                    cn[e] = l;
                    nst[nsi ++] = e;
                }
            }
        }

        l ++;
        si = nsi;
        nsi = 0;
        st = st == sta ? stb : sta;
        nst = nst == sta ? stb : sta;
        cb = cb == rs ? bs : rs;
        cn = cn == rn ? bn : rn;
    }

    int* r = malloc(sizeof(int) * n);
    r[0] = 0;

    for (int i = 1; i < n; i ++)
        r[i] = (rn[i] < bn[i] ? (rn[i] ? rn[i] : bn[i]) : (bn[i] ? bn[i] : rn[i])) - 1;

    *returnSize = n;
    return r;
}

