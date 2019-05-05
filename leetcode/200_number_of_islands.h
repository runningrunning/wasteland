void tag(char** grid, int x, int y, int r, int c)
{
    grid[x][y] = '2';

    if (x && grid[x - 1][y] == '1')
        tag(grid, x - 1, y, r, c);

    if (y && grid[x][y - 1] == '1')
        tag(grid, x, y - 1, r, c);

    if (x < r - 1 && grid[x + 1][y] == '1')
        tag(grid, x + 1, y, r, c);

    if (y < c - 1 && grid[x][y + 1] == '1')
        tag(grid, x, y + 1, r, c);
}

// int maxAreaOfIsland(int** grid, int gridRowSize, int gridColSize)
int numIslands(char** grid, int gridRowSize, int gridColSize)
{
    if (!grid || !gridRowSize || !gridColSize)
        return 0;

    int t = 0;
    for (int i = 0; i < gridRowSize; i ++)
    {
        for (int j = 0; j < gridColSize; j ++)
        {
            if (grid[i][j] == '1')
            {
                t ++;
                tag(grid, i, j, gridRowSize, gridColSize);
            }
        }
    }
    return t;
}

