// STUPID ME, find better solution here !!!
// more understand code here ??
// think too much?
// clear mind !!!!
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool _esn(int** g, int* gs, int* n, int ni, char* f, char* u, char* m)
{
    int x = n[ni - 1];
    for (int i = 0; i < gs[x]; i ++)
    {
        int y = g[x][i];

        if (m[y])
            continue;

        if (f[y] || u[y])
        {
            int ti = ni - 1;
            while (ti >= 0)
            {
                u[n[ti]] = 1;
                ti --;
            }
            u[y] = 1;
            return true;
        }
        else
        {
            f[y] = 1;
            n[ni] = y;
            if (_esn(g, gs, n, ni + 1, f, u, m))
            {
                f[y] = 0;
                return true;
            }
            f[y] = 0;
        }
    }
    return false;
}

void _mask(int** g, int* gs, int* n, int ni, char* m)
{
    int x = n[ni - 1];
    for (int i = 0; i < gs[x]; i ++)
    {
        int y = g[x][i];
        if (!m[y])
        {
            m[y] = 1;
            n[ni] = y;
            /* r[*ri] = y; */
            /* (*ri) ++; */
            _mask(g, gs, n, ni + 1, m);
        }
    }
}

int* eventualSafeNodes(int** graph, int graphRowSize, int *graphColSizes, int* returnSize)
{
    char* u = calloc(sizeof(char), graphRowSize);
    char* f = calloc(sizeof(char), graphRowSize);
    char* m = calloc(sizeof(char), graphRowSize);
    int* n = malloc(sizeof(int) * graphRowSize);

    int ni = 0;
    int ri = 0;

    for (int i = 0; i < graphRowSize; i ++)
    {
        if (u[i] || m[i])
            continue;

        if (!graphColSizes[i])
        {
            if (!m[i])
            {
                m[i] = 1;
                // r[ri ++] = i;
            }
            continue;
        }

        f[i] = 1;
        n[0] = i;
        bool e = _esn(graph, graphColSizes, n, 1, f, u, m);
        if (!e)
        {
            if (!m[i])
            {
                m[i] = 1;
                // r[ri ++] = i;
                _mask(graph, graphColSizes, n, 1, m);
            }
        }
        f[i] = 0;
    }
    /* *returnSize = ri; */

    /* if (!ri) */
    /*     return NULL; */

    // int* ret = malloc(sizeof(int) * ri);
    // memcpy(ret, r, sizeof(int) * ri);
    // _esn_sort(ret, 0, ri - 1);

    for (int i = 0; i < graphRowSize; i ++)
        if (m[i])
            n[ri ++] = i;
    *returnSize = ri;
    return n;
}

/*
void _esn(int** g, int* gs, int* n, int ni, char* f, char* u, bool* ret)
{
    int x = n[ni - 1];
    for (int i = 0; i < gs[x]; i ++)
    {
        int y = g[x][i];

        if (!u[y])
        {
            *ret = true;
            continue;
        }

        if (f[y] || u[y])
        {
            int ti = ni - 1;
            while (ti >= 0)
            {
                u[n[ti]] = 1;
                ti --;
            }
            u[y] = 1;
        }
        else
        {
            f[y] = 1;
            n[ni] = y;
            _esn(g, gs, n, ni + 1, f, u, ret);
            f[y] = 0;
        }
    }
}

void _mask(int** g, int* gs, int* n, int ni, char* m, int* r, int* ri)
{
    int x = n[ni - 1];
    for (int i = 0; i < gs[x]; i ++)
    {
        int y = g[x][i];
        if (!m[y])
        {
            m[y] = 1;
            n[ni] = y;
            r[*ri] = y;
            (*ri) ++;
            _mask(g, gs, n, ni + 1, m, r, ri);
        }
    }
}

void _esn_sort(int* n, int s, int e)
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

    _esn_sort(n, cs, e - 1);
    _esn_sort(n, e + 1, ce);
}
int* eventualSafeNodes(int** graph, int graphRowSize, int *graphColSizes, int* returnSize)
{
    char* u = calloc(sizeof(char), graphRowSize);
    char* f = calloc(sizeof(char), graphRowSize);
    char* m = calloc(sizeof(char), graphRowSize);
    int* n = malloc(sizeof(int) * graphRowSize);
    int* r = malloc(sizeof(int) * graphRowSize);

    printf("here.\n");

    int ri = 0;
    for (int i = 0; i < graphRowSize; i ++)
    {
        if (u[i] || m[i])
            continue;

        if (!graphColSizes[i])
        {
            m[i] = 1;
            r[ri ++] = i;
            continue;
        }

        f[i] = 1;
        n[0] = i;
        bool e = false;
        _esn(graph, graphColSizes, n, 1, f, u, &e);
        if (!e && !u[i])
        {
            r[ri ++] = i;
            m[i] = 1;
            _mask(graph, graphColSizes, n, 1, m, r, &ri);
        }
        f[i] = 0;
    }
    *returnSize = ri;

    if (!ri)
        return NULL;

    int* ret = malloc(sizeof(int) * ri);
    memcpy(ret, r, sizeof(int) * ri);
    _esn_sort(ret, 0, ri - 1);
    return ret;
}
*/
