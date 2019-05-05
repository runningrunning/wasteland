void tag(int** grid, int t, int x, int y, int r, int c, int* n)
{
    if (grid[x][y] == 1)
    {
        (*n) ++;
        grid[x][y] = t;
    }

    if (x && grid[x - 1][y] == 1)
        tag(grid, t, x - 1, y, r, c, n);

    if (y && grid[x][y - 1] == 1)
        tag(grid, t, x, y - 1, r, c, n);

    if (x < r - 1 && grid[x + 1][y] == 1)
        tag(grid, t, x + 1, y, r, c, n);

    if (y < c - 1 && grid[x][y + 1] == 1)
        tag(grid, t, x, y + 1, r, c, n);
}

int maxAreaOfIsland(int** grid, int gridRowSize, int gridColSize)
{
    int max = INT_MIN;

    int t = 2;

    for (int i = 0; i < gridRowSize; i ++)
    {
        for (int j = 0; j < gridColSize; j ++)
        {
            if (grid[i][j] == 1)
            {
                int n = 0;
                tag(grid, t ++, i, j, gridRowSize, gridColSize, &n);

                if (max < n)
                    max = n;
            }
        }
    }
    return max == INT_MIN ? 0 : max;
}
