// think too much !, must find a better way !
int _lar(int** ns, int* r, int* q, int x)
{
    if (r[x])
        return r[x] - 1;

    if (!ns[x])
        r[x] = x + 1;
    else
    {
        int l = ns[x][0];
        int min_i = x;
        int min = q[x];
        for (int i = 1; i < l; i ++)
        {
            int t = _lar(ns, r, q, ns[x][i]);
            if (min > q[t])
            {
                min = q[t];
                min_i = t;
            }
        }
        r[x] = min_i + 1;
    }
    return r[x] - 1;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* loudAndRich(int** richer, int richerRowSize, int *richerColSizes, int* quiet, int quietSize, int* returnSize)
{
    *returnSize = 0;
    if (!quiet || !quietSize)
        return NULL;

    *returnSize = quietSize;
    int** ns = calloc(sizeof(int*), quietSize);

    for (int i = 0; i < richerRowSize; i ++)
    {
        int x = richer[i][0];
        int y = richer[i][1];

        if (!ns[y])
        {
            ns[y] = malloc(sizeof(int) * 2);
            ns[y][0] = 2;
            ns[y][1] = x;
        }
        else
        {
            int l = ns[y][0];
            ns[y] = realloc(ns[y], sizeof(int) * (l + 1));
            ns[y][0] = l + 1;
            ns[y][l] = x;
        }
    }
    int* r = calloc(sizeof(int), quietSize);

    for (int i = 0; i < quietSize; i ++)
    {
        if (!r[i])
            _lar(ns, r, quiet, i);
    }

    for (int i = 0; i < quietSize; i ++)
        r[i] -= 1;
    return r;
}
