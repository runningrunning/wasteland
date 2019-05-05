// depth or bread searches
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void populated(int** m, int r, int c, int x, int y, char* bs)
{
    if (bs[x * c + y])
        return;
    bs[x * c + y] = 1;

    int t = m[x][y];

    if (x && m[x - 1][y] >= t)
        populated(m, r, c, x - 1, y, bs);
    if (y && m[x][y - 1] >= t)
        populated(m, r, c, x, y - 1, bs);
    if (x != r - 1 && m[x + 1][y] >= t)
        populated(m, r, c, x + 1, y, bs);
    if (y != c - 1 && m[x][y + 1] >= t)
        populated(m, r, c, x, y + 1, bs);
}

int** pacificAtlantic(int** m, int r, int *cs, int** rcs, int* rs)
{
    *rcs = NULL;
    *rs = 0;

    if (!m || !r || !cs || !cs[0])
        return NULL;

    int s = 0;
    int c = cs[0];
    int** ret = NULL;

    char* bs = malloc(r * c);
    char* ts = malloc(r * c);

    bzero(bs, r * c);
    bzero(ts, r * c);

    for (int i = 0; i < r; i ++)
        populated(m, r, c, i, 0, bs);
    for (int i = 0; i < c; i ++)
        populated(m, r, c, 0, i, bs);

    for (int i = 0; i < r; i ++)
        populated(m, r, c, i, c - 1, ts);

    for (int i = 0; i < c; i ++)
        populated(m, r, c, r - 1, i, ts);

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
            if (bs[i * c + j] && ts[i * c + j])
            {
                if (!ret)
                    ret = malloc(sizeof(int*));
                else
                    ret = realloc(ret, sizeof(int*) * (s + 1));
                ret[s] = malloc(sizeof(int) * 2);
                ret[s][0] = i;
                ret[s][1] = j;
                s ++;
            }

    *rs = s;
    cs = malloc(sizeof(int) * s);
    for (int i = 0; i < s; i ++)
        cs[i] = 2;
    *rcs = cs;

    return ret;
}
