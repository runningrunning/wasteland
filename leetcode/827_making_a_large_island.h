void count(int** g, int r, int c, int x, int y, int* num, long* f)
{
    if (f[x] & (1L << y))
        return;

    f[x] |= 1L << y;
    (*num) ++;

    if (x && g[x - 1][y])
        count(g, r, c, x - 1, y, num, f);
    if (x < r && g[x + 1][y])
        count(g, r, c, x + 1, y, num, f);
    if (y && g[x][y - 1])
        count(g, r, c, x, y - 1, num, f);
    if (y < c && g[x][y + 1])
        count(g, r, c, x, y + 1, num, f);
}

void mark(int** g, int r, int c, int x, int y, int num, int id)
{
    g[x][y] = id + num;
    if (x && g[x - 1][y] == 1)
        mark(g, r, c, x - 1, y, num, id);
    if (x < r && g[x + 1][y] == 1)
        mark(g, r, c, x + 1, y, num, id);
    if (y && g[x][y - 1] == 1)
        mark(g, r, c, x, y - 1, num, id);
    if (y < c && g[x][y + 1] == 1)
        mark(g, r, c, x, y + 1, num, id);
}

int largestIsland(int** grid, int gridRowSize, int *gridColSizes)
{
    if (!gridRowSize)
        return 0;

    long* gf = calloc(sizeof(long), gridRowSize);

    int id = 0;
    int max = 0;
    int r = gridRowSize - 1;
    int c = gridColSizes[0] - 1;

    for (int i = 0; i <= r; i ++)
    {
        for (int j = 0; j <= c; j ++)
        {
            if (gf[i] & (1L << j) || (!grid[i][j]))
                continue;
            int num = 0;
            count(grid, r, c, i, j, &num, gf);
            if (num > max)
                max = num;
            mark(grid, r, c, i, j, num, (++ id) << 16);
        }
    }

    int** g = grid;
    for (int i = 0; i <= r; i ++)
        for (int j = 0; j <= c; j ++)
        {
            if (g[i][j])
                continue;

            int li = -1;
            int ri = -1;
            int ui = -1;
            int di = -1;

            int a = 0;

            if (i)
            {
                ui = g[i - 1][j] >> 16;
                a += (g[i - 1][j] & 0xFFFF);
            }

            if (i != r)
            {
                di = g[i + 1][j] >> 16;
                if (di != ui)
                    a += (g[i + 1][j] & 0xFFFF);
            }

            if (j)
            {
                li = g[i][j - 1] >> 16;
                if (li != ui && li != di)
                    a += (g[i][j - 1] & 0xFFFF);
            }

            if (j != c)
            {
                ri = g[i][j + 1] >> 16;
                if (ri != ui && ri != di && ri != li)
                    a += (g[i][j + 1] & 0xFFFF);
            }

            if (a + 1 > max)
                max = a + 1;
        }
    return max;
}
