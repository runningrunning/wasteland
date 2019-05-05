bool _popu(int** g, int r, int c, int x, int y, int* n, int id, int oid)
{
    if (x < 0 || y < 0 || x >= r || y >= c || !g[x][y] || g[x][y] == id)
        return true;

    if (x == 0 || g[x][y] > oid)
        return false;

    (*n) ++;
    g[x][y] = id;

    return _popu(g, r, c, x - 1, y, n, id, oid)
        && _popu(g, r, c, x + 1, y, n, id, oid)
        && _popu(g, r, c, x, y - 1, n, id, oid)
        && _popu(g, r, c, x, y + 1, n, id, oid);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* hitBricks(int** grid, int gridRowSize, int *gridColSizes, int** hits, int hitsRowSize, int *hitsColSizes, int* returnSize)
{
    *returnSize = 0;
    if (!grid || !gridRowSize || !gridColSizes || !hits || !hitsRowSize || !hitsColSizes)
        return 0;

    int** g = grid;
    int* ret = malloc(sizeof(int) * hitsRowSize);

    int r = gridRowSize;
    int c = gridColSizes[0];

    int id = 2;
    for (int i = 0; i < hitsRowSize; i ++)
    {
        int x = hits[i][0];
        int y = hits[i][1];

        if (g[x][y] == 0)
        {
            ret[i] = 0;
            continue;
        }

        g[x][y] = 0;

        int num = 0;
        int n = 0;

        int oid = id ++;

        if (x && _popu(g, r, c, x - 1, y, &n, oid, oid))
        {
            num += n;
            _popu(g, r, c, x - 1, y, &n, 0, INT_MAX);
        }

        n = 0;
        if (y && _popu(g, r, c, x, y - 1, &n, id ++, oid))
        {
            num += n;
            _popu(g, r, c, x, y - 1, &n, 0, INT_MAX);
        }

        n = 0;
        if (x != r - 1 && _popu(g, r, c, x + 1, y, &n, id ++, oid))
        {
            num += n;
            _popu(g, r, c, x + 1, y, &n, 0, INT_MAX);
        }

        n = 0;
        if (y != c - 1 && _popu(g, r, c, x, y + 1, &n, id ++, oid))
        {
            num += n;
            _popu(g, r, c, x, y + 1, &n, 0, INT_MAX);
        }
        ret[i] = num;
    }

    *returnSize = hitsRowSize;
    return ret;
}
