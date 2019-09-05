// optimization !!!
// find better way
int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
    int** g = grid;
    int r = gridSize;
    int c = gridColSize[0];

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if (grid[i][j])
            {
                if (i)
                    grid[i][j] += (grid[i - 1][j] & 0xFFFFFF00);

                if (j)
                    grid[i][j] += grid[i][j - 1] & 0xFF;

                grid[i][j] += 0x100;
            }
        }

    int max = r < c ? r : c;

    for (; max > 0; max --)
    {
        int max_x = max << 8;
        int max_y = max;

        for (int i = 0; i < r - max + 1; i ++)
            for (int j = 0; j < c - max + 1; j ++)
            {
                if (g[i][j])
                {
                    int x = i + max - 1;
                    int y = j + max - 1;

                    if (g[x][j] >= max_x && g[x][y] >= max_x && (g[x][y] & 0xFF) >= max_y
                        && (g[i][y] & 0xFF) >= max_y)
                        return max * max;
                }
            }
    }

    return 0;
}


/* too slow
bool is(int** g, int x, int y, int n)
{
    int x1 = x;
    int x2 = x + n - 1;
    int y1 = y;
    int y2 = y + n - 1;

    for (int i = 0; i < n; i ++)
    {
        if (!g[x1][i + y] || !g[x2][i + y])
            return false;

        if (!g[i + x][y1] || !g[i + x][y2])
            return false;
    }
    return true;
}

int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
    int** g = grid;
    int r = gridSize;
    int c = gridColSize[0];

    int* rn = calloc(sizeof(int),  r);
    int* cn = calloc(sizeof(int), c);

    int max = r < c ? r : c;

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            rn[i] += g[i][j];
            cn[j] += g[i][j];
        }

    for (; max >= 0; max --)
    {
        if (!max)
            break;

        for (int i = 0; i < r - max + 1; i ++)
            for (int j = 0; j < c - max + 1; j ++)
            {
                if (rn[i] < max || rn[i + max - 1] < max)
                    continue;

                if (cn[j] < max || cn[j + max - 1] < max)
                    continue;

                if (is(g, i, j, max))
                    return max * max;
            }
    }
    return 0;
}
*/
