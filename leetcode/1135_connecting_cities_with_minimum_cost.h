// simple is faster
// just simple union finder
// how to prove ?
// remove edges and test connect
// no directed graph !
// similar with 1059 ?
// greedy or dp or just DFS
int comp_d(const void* a, const void* b)
{
    return (*((int**)a))[2] - (*((int**)b))[2];
}

int root(int s, int* ns)
{
    while (s != ns[s])
        s = ns[ns[s]];
    return s;
}

int minimumCost(int N, int** connections, int connectionsSize, int* connectionsColSize)
{
    qsort(connections, connectionsSize, sizeof(int*), comp_d);
    int* ns = calloc(sizeof(int), N + 1);

    int all = 0;
    int us = 0;
    int cs = 0;

    for (int i = 0; i < connectionsSize; i ++)
    {
        int* c = connections[i];
        int s = c[0];
        int e = c[1];
        int d = c[2];

        if (ns[s] && ns[e])
        {
            int rs = root(s, ns);
            int re = root(e, ns);
            if (rs == re)
                continue;
            ns[rs] = re;
            us --;
        }
        else
        {
            if (ns[s])
            {
                ns[e] = s;
                cs ++;
            }
            else if (ns[e])
            {
                ns[s] = e;
                cs ++;
            }
            else
            {
                ns[s] = s;
                ns[e] = s;
                us ++;
                cs += 2;
            }
        }

        all += d;
        if (us == 1 && cs == N)
            return all;
    }
    return -1;
}


/*
int comp_s(const void* a, const void* b)
{
    return (*((int**)a))[0] - (*((int**)b))[0];
}

bool connected(int** c, int cs, int* ss, int s, int* bs, int a, int n)
{
    if (a == n)
        return true;

    if (!ss[s - 1])
        return false;

    for (int i = ss[s - 1]; i < cs; i ++)
    {
        int* e = c[i];
        if (e[0] != s)
            break;

        if (e[2] == -1)
            continue;

        if (bs[e[1] - 1])
            continue;
        bs[e[1] - 1] = 1;
        if (connected(c, cs, ss, e[1] - 1, bs, a + 1, n))
        {
            bs[e[1] - 1] = 0;
            return true;
        }
        bs[e[1] - 1] = 0;
    }
    return false;
}

int minimumCost(int N, int** connections, int connectionsSize, int* connectionsColSize)
{
    int** cs = malloc(sizeof(int*) * connectionsSize);
    memcpy(cs, connections, sizeof(int*) * connectionsSize);

    qsort(cs, connectionsSize, sizeof(int*), comp_d);
    qsort(connections, connectionsSize, sizeof(int*), comp_s);

    int* ss = calloc(sizeof(int), N);

    long all = 0L;
    for (int i = 0; i < connectionsSize; i ++)
    {
        int* c = connections[i];
        if (!ss[c[0] - 1])
            ss[c[0] - 1] = i + 1;
        all += c[2];
    }

    int* bs = calloc(sizeof(int), N);
    bs[0] = 1;

    if (!connected(connections, connectionsSize, ss, 1, bs, 1, N))
        return -1;

    int left = connectionsSize;
    for (int i = 0; i < connectionsSize; i ++)
    {
        if (left == N - 1)
            return (int) all;

        int* c = cs[i];
        int d = c[2];
        c[2] = -1;

        if (!connected(connections, connectionsSize, ss, 1, bs, 1, N))
            c[2] = d;
        else
        {
            all -= d;
            left --;
        }
    }
    return (int) all;
}
*/
