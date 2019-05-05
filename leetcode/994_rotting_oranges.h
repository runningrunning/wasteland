int orangesRotting(int** grid, int gridRowSize, int gridColSize)
{
    /* if (!grid || !gridRowSize || !gridColSize) */
    /*     return 0; */

    int gridRowSize = grid.size();
    if (!gridRowSize)
        return 0;
    int girdColSize = grid[0].size();

    int an = 0;
    int* a = (int*) malloc(sizeof(int) * gridRowSize * gridColSize);
    int bn = 0;
    int* b = (int*) malloc(sizeof(int) * gridRowSize * gridColSize);

    int num = 0;
    for (int i = 0; i < gridRowSize; i ++)
        for (int j = 0; j < gridColSize; j ++)
        {
            if (grid[i][j] == 2)
                a[an ++] = i << 16 | j;
            else if (grid[i][j] == 1)
                num ++;
        }

    int t = 0;
    while (an && num)
    {
        for (int i = 0; i < an; i ++)
        {
            int x = a[i] >> 16;
            int y = a[i] & 0xFFFF;

            if (x && grid[x - 1][y] == 1)
            {
                num --;
                b[bn ++] = (x - 1) << 16 | y;
                grid[x - 1][y] = 2;
            }

            if (y && grid[x][y - 1] == 1)
            {
                num --;
                b[bn ++] = x << 16 | (y - 1);
                grid[x][y - 1] = 2;
            }

            if ((x != gridRowSize - 1) && grid[x + 1][y] == 1)
            {
                num --;
                b[bn ++] = (x + 1) << 16 | y;
                grid[x + 1][y] = 2;
            }

            if ((y != gridColSize - 1) && grid[x][y + 1] == 1)
            {
                num --;
                b[bn ++] = x << 16 | (y + 1);
                grid[x][y + 1] = 2;
            }
        }

        int* _t = b;
        b = a;
        a = _t;
        an = bn;
        bn = 0;
        t ++;
    }
    return num ? -1 : t;
}
