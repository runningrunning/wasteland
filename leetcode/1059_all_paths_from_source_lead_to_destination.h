// FUN, learn a lot
// READ the QS, it just mention from source to destination
// it could be loop in other place but has nothing to do with source to destination !!!
// has loop false, has more than one destination false
// how to check loop error
// FUN, learn a lot
// has loop false, has more than one destination false
// how to check loop error
int comp(const void* a, const void* b)
{
    return (*((int**)a))[0] - (*((int**)b))[0];
}

bool has_loop_wrong_end(int* ss, int** e, int el, int* ns, int s, int o, int* dp)
{
    if (!ss[s])
        return s != o;

    if (dp[s])
        return false;

    for (int i = ss[s] - 1; i < el; i ++)
    {
        int* d = e[i];

        if (d[0] != s)
            break;

        if (ns[d[1]])
            return true;

        ns[d[1]] = 1;
        if (has_loop_wrong_end(ss, e, el, ns, d[1], o, dp))
            return true;
        ns[d[1]] = 0;
    }

    dp[s] = 1;
    return false;
}

bool leadsToDestination(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination)
{
    if (source == destination)
        return n == 1 && !edgesSize;

    int ins = 0;
    int outs = 0;

    int* ns = calloc(sizeof(int), n);
    int* ss = calloc(sizeof(int), n);

    qsort(edges, edgesSize, sizeof(int*), comp);

    for (int i = 0; i < edgesSize; i ++)
    {
        int* d = edges[i];
        int s = d[0];
        int e = d[1];

        /* if (s == e) */
        /*     return false; */

        if (!ss[s])
            ss[s] = i + 1;

        /* if (!(ns[s] >> 16)) */
        /*     outs ++; */

        /* if (!(ns[e] & 0xFFFF)) */
        /*     ins ++; */

        /* ns[s] += 1 << 16; */
        /* ns[e] += 1; */

        /* if (e == source) */
        /*     return false; */

        /* if (s == destination) */
        /*     return false; */
    }

    /* if (outs != n - 1 || ins != n - 1) */
    /*     return false; */

    // how to detect loop ?
    // DFS
    memset(ns, 0, sizeof(int) * n);
    int* dp = calloc(sizeof(int), n);
    ns[source] = 1;
    return !has_loop_wrong_end(ss, edges, edgesSize, ns, source, destination, dp);

    /*
    int* sta = malloc(sizeof(int) * n);
    int* stb = malloc(sizeof(int) * n);

    int nsi = 0;
    int si = 0;
    int* st = sta;
    int* nst = stb;
    st[si ++] = source;

    int id = 1;

    while (si)
    {
        for (int i = 0; i < si; i ++)
        {
            int s = st[i];

            for (int j = ss[s] - 1; j < edgesSize; j ++)
            {
                int* d = edges[j];
                if (d[0] != s)
                    break;

                if (d[1] == destination)
                    continue;

                if (ns[d[1]] && ns[d[1]] != id)
                    return false;

                if (!ns[d[1]])
                    nst[nsi ++] = d[1];

                ns[d[1]] = id;
            }
        }

        id ++;
        si = nsi;
        st = st == sta ? stb : sta;
        nst = nst == sta ? stb : sta;
        nsi = 0;
    }
    return true;
    */
}

