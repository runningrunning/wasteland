// invalid test case !!!
void ndt_sort(int* n, int s, int e)
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

    ndt_sort(n, cs, e - 1);
    ndt_sort(n, e + 1, ce);
}

int networkDelayTime(int** times, int timesRowSize, int timesColSize, int N, int K)
{
    int* ts = malloc(sizeof(int) * timesRowSize);
    for (int i = 0; i < timesRowSize; i ++)
        ts[i] = times[i][0] << 16 | times[i][1] << 8 | times[i][2];
    ndt_sort(ts, 0, timesRowSize - 1);

    int* is = calloc(sizeof(int), (N + 1));
    int pre = 0;
    for (int i = 0; i < timesRowSize; i ++)
    {
        if ((ts[i] & 0xFF0000) != (pre & 0xFF0000))
            is[ts[i] >> 16] = i + 1;
        pre = ts[i];
    }


    int si = 0;
    int* ns = calloc(sizeof(int), (N + 1));
    int* st = malloc(sizeof(int) * (N + 1));
    st[si ++] = K;

    char* fs = malloc(N + 1);
    bzero(fs, N + 1);
    fs[K] = 1;

    while (si)
    {
        si --;

        int node = st[si];
        int time = ns[node];

        if (!is[node])
            continue;

        int x = is[node] - 1;

        for (x; x < timesRowSize; x ++)
        {
            if ((ts[x] >> 16) != node)
                break;

            int _y = (ts[x] >> 8) & 0xFF;
            int _t = ts[x] & 0xFF;

            if (!fs[_y] || ns[_y] > _t + time)
            {
                fs[_y] = 1;
                ns[_y] = _t + time;
                st[si ++] = _y;
            }
        }
    }

    int max = INT_MIN;
    for (int i = 1; i <= N; i ++)
    {
        if (!fs[i])
            return -1;
        else if (ns[i] > max)
            max = ns[i];
    }
    return max;
}
