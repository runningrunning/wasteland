// just be careful, corner case
// node not list in the edges, then it's 1
// graph ?
// simple stack
int reachableNodes(int** edges, int edgesRowSize, int *edgesColSizes, int M, int N)
{
    int** nodes = calloc(sizeof(int*), N);
    int* nums = calloc(sizeof(int), N);
    bool has_start = false;

    for (int i = 0; i < edgesRowSize; i ++)
    {
        int x = edges[i][0];
        int y = edges[i][1];

        nodes[x] = realloc(nodes[x], sizeof(int) * (nums[x] + 1));
        nodes[x][nums[x]] = i;
        nums[x] ++;

        nodes[y] = realloc(nodes[y], sizeof(int) * (nums[y] + 1));
        nodes[y][nums[y]] = i;
        nums[y] ++;

        if (!x || !y)
            has_start = true;
    }

    if (!has_start)
        return 1;

    int* r = calloc(sizeof(int), N);
    int* f = calloc(sizeof(int), N);
    long* st = malloc(sizeof(long) * N);
    long* bst = malloc(sizeof(long) * N);

    int sti = 0;
    int bsti = 0;

    r[0] = M + 1;
    st[sti ++] = M;

    while (sti)
    {
        bsti = 0;
        memset(f, 0, sizeof(int) * N);

        while (sti)
        {
            long x = st[-- sti];
            long node = x >> 32;
            long num = x & 0xFFFFFFFF;

            if (!num)
                continue;

            for (int i = 0; i < nums[node]; i ++)
            {
                int e = nodes[node][i];
                long y = edges[e][0] == node ? edges[e][1] : edges[e][0];
                int l = edges[e][2];

                if (num - l > r[y])
                {
                    l = num - l;
                    r[y] = l;

                    if (l > 1)
                    {
                        if (!f[y])
                        {
                            bst[bsti ++] = y << 32 | l - 1;
                            f[y] = bsti;
                        }
                        else //  if (l > (bst[f[y] - 1]) & 0xFFFFFFFF)
                            bst[f[y] - 1] = y << 32 | l - 1;
                    }
                }
            }
        }

        long* t = st;
        st = bst;
        bst = t;
        sti = bsti;
    }

    int all = 0;
    memset(f, 0, sizeof(int) * N);

    for (int i = 0; i < edgesRowSize; i ++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        int num = edges[i][2];

        if (r[x] && !f[x])
        {
            f[x] = 1;
            all ++;
        }

        if (r[y] && !f[y])
        {
            f[y] = 1;
            all ++;
        }

        if (r[x] && r[y])
        {
            if (r[x] + r[y] - 2 > num)
                all += num;
            else
                all += r[x] + r[y] - 2;
        }
        else if (r[x] || r[y])
        {
            all += r[x] + r[y] - 1;
        }
    }
    return all;
}
