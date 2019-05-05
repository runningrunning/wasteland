int projectionArea(int** grid, int gridRowSize, int *gridColSizes)
{
    if (!gridRowSize || !gridColSizes[0])
        return 0;

    int r = 0;

    for (int i = 0; i < gridRowSize; i ++)
    {
        int rc = grid[i][0];
        for (int j = 0; j < gridColSizes[i]; j ++)
        {
            int x = grid[i][j];

            if (x)
                r ++;

            if (x > rc)
                rc = x;

            if (x > grid[0][j])
                grid[0][j] = x;
        }

        r += rc;
    }

    for (int i = 0; i < gridColSizes[0]; i ++)
        r += grid[0][i];

    return r;
}
