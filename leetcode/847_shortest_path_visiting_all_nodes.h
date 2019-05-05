// don't need to use graph ?? peek hint !! BFS ?
// BFS, just like 865 shortest path t0 get all keys
int shortestPathLength(int** graph, int graphRowSize, int *graphColSizes)
{
    if (graphRowSize < 2)
        return 0;

    // check redundant, status can be remembered?
    int* bits = calloc(sizeof(int), 4096);

    int* a = malloc(sizeof(int) * 256);
    int* b = malloc(sizeof(int) * 256);

    int ns = 256;
    int cs = 256;

    int ci = 0;
    int ni = 0;
    int* c = a;
    int* n = b;

#define MARK(x) do {bits[(x) / 32] |= 1 << ((x) % 32); } while (0)
#define IS_MARK(x) (bits[(x) / 32] & (1 << ((x) % 32)))

    int all = (1 << graphRowSize) - 1;

    for (int i = 0; i < graphRowSize; i ++)
    {
        MARK(i << 13);
        c[ci ++] = i << 13 | (1 << i);
    }

    int step = 0;

    while (true)
    {
        step ++;

        if (ci == 0)
            return -1;

        for (int i = 0; i < ci; i ++)
        {
            int x = c[i] >> 13;
            int* gx = graph[x];

            /* printf("step %d x is %d %x.\n", step, x, c[i]); */
            /* out(gx, graphColSizes[x]); */

            for (int j = 0; j < graphColSizes[x]; j ++)
            {
                int y = gx[j];
                int t = y << 13 | (c[i] & 0x1FFF) | 1 << y;

                if ((t & all) == all)
                    return step;

                if (!IS_MARK(t))
                {
                    if (ni == ns)
                    {
                        ns *= 2;
                        n = realloc(n, sizeof(int) * ns);
                        // printf("ni is %d ns is %d.\n", ni, ns);
                    }

                    n[ni ++] = t;
                    MARK(t);
                }
            }
        }

        ci = ni;

        ni = ns;
        ns = cs;
        cs = ni;
        ni = 0;

        int* t = n;
        n = c;
        c = t;

    }

    return step;
}
