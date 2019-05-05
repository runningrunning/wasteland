// just walking
// how to memory those steps ?
// how to improve the performance ?

int up_III(int** grid, int x, int y, int r, int c, int num, int all)
{
    if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] < 0)
        return 0;

    num ++;
    if (grid[x][y] == 2 && num == all)
        return 1;

    int o = grid[x][y];
    grid[x][y] = -1;
    int t = up_III(grid, x - 1, y, r, c, num, all);
    t += up_III(grid, x + 1, y, r, c, num, all);
    t += up_III(grid, x, y - 1, r, c, num, all);
    t += up_III(grid, x, y + 1, r, c, num ,all);
    grid[x][y] = o;

    return t;
}

int uniquePathsIII(int** grid, int gridRowSize, int* gridColSizes)
{
    if (!gridRowSize || !gridColSizes[0])
        return 0;

    int num = 0;
    int s_x = 0;
    int s_y = 0;
    for (int i = 0; i < gridRowSize; i ++)
        for (int j = 0; j < gridColSizes[0]; j ++)
            if (grid[i][j] >= 0)
            {
                num ++;
                if (grid[i][j] == 1)
                {
                    s_x = i;
                    s_y = j;
                }
            }
    return up_III(grid, s_x, s_y, gridRowSize, gridColSizes[0], 0, num);
}
