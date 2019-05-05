#define FMASK 0x80000000
#define VMASK 0x7FFFFFFF
#define PRIMER 4099

bool is_same(int** grid, int r, int c, int x1, int y1, int x2, int y2, int id)
{
    if (x2 < 0 || x2 == r || y2 < 0 || y2 == c || !grid[x2][y2])
    {
        return false;
    }

    grid[x1][y1] = id;

    if (x1 && grid[x1 - 1][y1] && grid[x1 - 1][y1] != id)
        if (!is_same(grid, r, c, x1 - 1, y1, x2 - 1, y2, id))
            return false;

    if (x1 != r - 1 && grid[x1 + 1][y1] && grid[x1 + 1][y1] != id)
        if (!is_same(grid, r, c, x1 + 1, y1, x2 + 1, y2, id))
            return false;

    if (y1 && grid[x1][y1 - 1] && grid[x1][y1 - 1] != id)
        if (!is_same(grid, r, c, x1, y1 - 1, x2, y2 - 1, id))
            return false;

    if (y1 != c - 1 && grid[x1][y1 + 1] && grid[x1][y1 + 1] != id)
        if (!is_same(grid, r, c, x1, y1 + 1, x2, y2 + 1, id))
            return false;
    return true;
}

int ndil(int** grid, int r, int c, int x, int y, int id, int* n)
{
    int v = 0;

    if (grid[x][y] == 1)
    {
        (*n) ++;
        grid[x][y] = id;
        v ++;
    }

    if (x && grid[x - 1][y] == 1)
        v = ((ndil(grid, r, c, x - 1, y, id, n) << 3) + 2) % PRIMER;

    if (x != r - 1 && grid[x + 1][y] == 1)
        v = (v * ((ndil(grid, r, c, x + 1, y, id, n) << 3) + 3)) % PRIMER;

    if (y && grid[x][y - 1] == 1)
        v = (v * ((ndil(grid, r, c, x, y - 1, id, n) << 3) + 4)) % PRIMER;

    if (y != c - 1 && grid[x][y + 1] == 1)
        v = (v * ((ndil(grid, r, c, x, y + 1, id, n) << 3) + 5)) % PRIMER;

    return v;
}

int numDistinctIslands(int** grid, int gridRowSize, int gridColSize)
{
    if (!gridRowSize || !gridColSize)
        return 0;

    int* hash = calloc(sizeof(int), PRIMER);
    int id = 2;
    int num = 0;

    for (int i = 0; i < gridRowSize; i ++)
        for (int j = 0; j < gridColSize; j ++)
            if (grid[i][j] == 1)
            {
                int t = 0;
                int h = ndil(grid, gridRowSize, gridColSize, i, j, id ++, &t);
                h = (h * t) % PRIMER;

                bool found = false;
                while (hash[h] & FMASK)
                {
                    int v = hash[h] & VMASK;

                    // just hash should be enough with n size
                    if ((v >> 16) == t)
                    {
                        found = true;
                        break;
                    }

/*
                   if (is_same(grid, gridRowSize, gridColSize, i, j, v >> 8, v & 0xFF, id ++) &&
                        is_same(grid, gridRowSize, gridColSize, v >> 8, v & 0xFF, i, j, id ++))
                    {
                        found = true;
                        break;
                    }
*/

                    h = (h + 1) % PRIMER;
                }

                if (!found)
                {
                    num ++;
                    hash[h] = FMASK | t << 16 | i << 8 | j;
                }
            }
    return num;
}
