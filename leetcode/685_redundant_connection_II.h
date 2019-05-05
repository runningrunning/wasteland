// try another solutions !!
// it's my way to do the directed graph !!
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int _parents(int* ns, int x)
{
    int c = 0;
    while (ns[x])
    {
        c = x;
        x = ns[x];
    }
    return (c << 16) | x;
}

bool _frdc(int** eds, int s, int e, int* ns, int np, int* r)
{
    for (int i = s; i <= e; i ++)
    {
        int u = eds[i][0];
        int v = eds[i][1];

        if (!ns[v] && (_parents(ns, u) & 0xFFFF) != v)
        {
            ns[v] = u;
            np ++;
        }
        else
        {
            int* nns = malloc(sizeof(int) * (e + 2));
            memcpy(nns, ns, sizeof(int) * (e + 2));

            int ou;
            int ov;

            int nu = u;
            int nv = v;

            if (ns[v])
            {
                ou = ns[v];
                ov = v;
            }
            else
            {
                // x -> y, u -> v
                int x = _parents(ns, u);
                int y = x >> 16;
                x &= 0xFFFF;

                ou = x;
                ov = y;
            }
            r[0] = u;
            r[1] = v;

            if (_frdc(eds, i + 1, e, nns, np, r))
            {
                free(nns);
                return true;
            }

            r[0] = ou;
            r[1] = ov;

            ns[ov] = 0;
            ns[nv] = nu;
        }
    }

    return np == e;
}

int* findRedundantDirectedConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize)
{
    *returnSize = 0;
    if (!edges || !edgesRowSize)
        return NULL;
    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);

    int* ns = calloc(sizeof(int), edgesRowSize + 1);
    _frdc(edges, 0, edgesRowSize - 1, ns, 0, ret);
    return ret;
}
