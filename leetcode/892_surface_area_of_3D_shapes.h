// be careful, try to add them
int surfaceArea(int** grid, int gridRowSize, int *gridColSizes)
{
    if (!gridRowSize || !gridColSizes[0])
        return 0;

    int rs = gridRowSize;
    int cs = gridColSizes[0];

    int a = 0;

    for (int i = 0; i < rs; i ++)
    {
        for (int j = 0; j < cs; j ++)
        {
            int l = grid[i][j];

            if (grid[i][j])
            {
                a += 4 * l + 2;

                if (i)
                    a -= grid[i - 1][j] > l ? l : grid[i - 1][j];

                if (i != rs - 1)
                    a -= grid[i + 1][j] > l ? l : grid[i + 1][j];

                if (j)
                    a -= grid[i][j - 1] > l ? l : grid[i][j - 1];

                if (j != cs - 1)
                    a -= grid[i][j + 1] > l ? l : grid[i][j + 1];
            }
        }
    }

    return a;
}
